// 2.69s	
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

#define DEBUG if( false )

struct node {
  int to;
  int steps = 0;
  bool visited = false;
};

// node nodes[1000000]; <- PROBLEMA ~ Mal cálculo de espacio
node nodes[1000010];

stack<int> q_nodes;
int main(){
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int e, t; cin >> e;
  for(int i = 1; i <= e; i++){
    // PROBLEMA ~ Como la entrada es muy grande, al tener doble asignación se exede el tiempo límite, quedó arreglado con cin.tie(0)
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

            for( int j = 0; j < len; j++ ){
              nodes[ q_nodes.top() ].steps = len;
              q_nodes.pop();
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
