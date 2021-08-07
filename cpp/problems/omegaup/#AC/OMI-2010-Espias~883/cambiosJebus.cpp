#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

bool debug = false;
#define DEBUG if(debug)

struct node {
  int to;
  int steps = 0;
  bool visited = false;
};

node nodes[1000000];

stack<int> q_nodes;

int main(){
  int e, t; 

  cin >> e;

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
      DEBUG printf("IN: %d\n", i);

      int current = i; 
      while(true){
        q_nodes.push(current);
        nodes[current].visited = true;
        current = nodes[current].to;
        DEBUG printf(" ~ %d\n", current);

        if(  nodes[ current ].visited  ){
          if( nodes[ current ].steps == 0 ){
            stack <int> q2; 
            int len;

            for( len = 1; !q_nodes.empty() && current != q_nodes.top(); len++ ){
              q2.push( q_nodes.top() ); 
              q_nodes.pop();
            }
            q2.push( q_nodes.top() ); 
            q_nodes.pop();

            while( !q2.empty() ){
              nodes[ q2.top() ].steps = len;
              q2.pop();
            }

          }
          break;
        }
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
