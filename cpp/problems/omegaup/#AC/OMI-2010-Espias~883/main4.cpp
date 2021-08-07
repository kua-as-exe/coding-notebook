#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define DEBUG if( false )

struct node {
  int to;
  int steps = 0;
  bool visited = false;
};

node nodes[1000010];

stack<int> q_nodes;

void printQ( stack<int> qt ){
  printf("[ ");
  while( !qt.empty() ){
    printf( "%d ,", qt.top() );
    qt.pop();
  }
  printf("]\n");
}

int main(){
  int e, t; cin >> e;
  for(int i = 1; i <= e; i++){
    cin >> t;
    nodes[i] = {t};
  }

  DEBUG {
    for( int i = 1; i <= e; i++ ){
      cout << nodes[i].to << " ";
    } cout << endl;
  }

  for(int i = 1; i <= e; i++){
    if( !nodes[i].visited ){

      int current = i; 
      while(true){
        q_nodes.push(current);
        DEBUG printf("IN: %d\n", current);
        if(  nodes[ nodes[current].to ].visited  ){
          nodes[current].visited = true; 
          if( nodes[ nodes[current].to ].steps == 0 ){
            DEBUG printf("found cicle: %d\n", nodes[current].to);

            int len = 1;
            for( int temp = nodes[ current ].to; temp != current; len++){
              DEBUG printf("%d \n", nodes[temp].to);
              temp = nodes[temp].to;
            }
            DEBUG printf("len: %d\n", len);

            int original = q_nodes.size(), t = 0;
            for( int j = 0; j < len; j++ ){
              DEBUG printf(" [0]");
              DEBUG printf("%d) Size: %d/%d", j, (int)q_nodes.size(), original);
              t = q_nodes.top();
              DEBUG printf(" [1]");
              nodes[t].steps = len;
              DEBUG printf(" [2]");
              q_nodes.pop();
              DEBUG printf(" [3]");
              DEBUG cout << endl;
            }
            break;

          }
          else {
            DEBUG printf("found breach: %d\n", nodes[current].to);
            current = nodes[current].to;
            break;
          }

        }
        nodes[current].visited = true;
        current = nodes[current].to;
      }


      while ( !q_nodes.empty() ){
        nodes[ q_nodes.top() ].steps = nodes[ nodes[ q_nodes.top() ].to ].steps+1;
        q_nodes.pop();
      }

    }
  }

  DEBUG printf("This is the end\n");
  int max = 0;
  for( int i = 1; i <= e; i++ ){
    DEBUG printf("%d: %d\n", i, nodes[i].steps);
    if( nodes[i].steps > max ) max = nodes[i].steps;
  }
  cout << max;

}
