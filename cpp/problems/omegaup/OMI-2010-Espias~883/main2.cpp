#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

bool debug = true;
#define DEBUG if(debug)

struct node {
  int to;
  int steps = 0;
  bool visited = false;
};

node nodes[1000000];

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
            stack <int> q2; int len;

            DEBUG printf("Before 0\n");
            DEBUG printf("Current: %d\n", current);
            /* DEBUG printQ(q_nodes); */
            /* DEBUG printQ(q2); */

            DEBUG printf("Before 1, q_nodes: %d\n", (int)q_nodes.size());
            for( len = 1; !q_nodes.empty() && nodes[current].to != q_nodes.top(); len++ ){
              printf("pre\n");
              q2.push( q_nodes.top() ); 
              printf(" - %d: %d (%d)\n", len, (int)q_nodes.top(), (int)q_nodes.size() );
              q_nodes.pop();
              printf("pos\n");
              printf("Next: %d & %d\n", nodes[current].to, q_nodes.top());
              printf("ready\n");
            }
            q2.push( q_nodes.top() ); q_nodes.pop();
            DEBUG printf("After 1\n");

            /* DEBUG printQ(q_nodes); */
            DEBUG printf("Before 2\n");
            DEBUG printQ(q2);
            DEBUG printf(" len: %d\n", len);
            while( !q2.empty() ){
              nodes[ q2.top() ].steps = len;
              q2.pop();
            }
            DEBUG printf("After 2\n");
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
