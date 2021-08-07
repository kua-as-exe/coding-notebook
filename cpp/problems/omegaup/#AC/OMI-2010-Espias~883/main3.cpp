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

vector<int> q_nodes(1000000);

void printQ( vector<int> qt ){
  printf("[ ");
  while( !qt.empty() ){
    printf( "%d ,", qt.back() );
    qt.pop_back();
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
        q_nodes.push_back(current);
        DEBUG printf("IN: %d\n", current);
        if(  nodes[ nodes[current].to ].visited  ){
          nodes[current].visited = true; 
          if( nodes[ nodes[current].to ].steps == 0 ){
            DEBUG printf("found cicle: %d\n", nodes[current].to);
            vector <int> q2(1000000); int len;

            DEBUG printf("Before 0\n");
            DEBUG printf("Current: %d\n", current);
            /* DEBUG printQ(q_nodes); */
            /* DEBUG printQ(q2); */

            DEBUG printf("Before 1, q_nodes: %d\n", (int)q_nodes.size());
            for( len = 1; !q_nodes.empty() && nodes[current].to != q_nodes.back(); len++ ){
              /* printf("pre\n"); */
              q2.push_back( q_nodes.back() ); 
              printf(" - %d: %d (%d)\n", len, (int)q_nodes.back(), (int)q_nodes.size() );
              q_nodes.pop_back();
              /* printf("pos\n"); */
              printf("Next: %d & %d\n", nodes[current].to, q_nodes.back());
              /* printf("ready\n"); */
            }
            q2.push_back( q_nodes.back() ); q_nodes.pop_back();
            DEBUG printf("After 1\n");

            /* DEBUG printQ(q_nodes); */
            DEBUG printf("Before 2\n");
            /* DEBUG printQ(q2); */
            DEBUG printf(" len: %d\n", len);
            while( !q2.empty() ){
              nodes[ q2.back() ].steps = len;
              q2.pop_back();
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
        nodes[ q_nodes.back() ].steps = nodes[ nodes[ q_nodes.back() ].to ].steps+1;
        q_nodes.pop_back();
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
