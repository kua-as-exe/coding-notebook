
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
  int visited = false;
};

// node nodes[1000000]; <- PROBLEMA ~ Mal cálculo de espacio
node nodes[1000010];

vector<int> q_nodes;

int main(){
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int e, t; cin >> e;
  for(int i = 1; i <= e; i++){
    // Como la entrada es muy grande, al tener doble asignación se exede el tiempo límite, quedó arreglado con cin.tie(0)
    cin >> t;
    nodes[i] = {t}; 
  }

  DEBUG {
    for( int i = 1; i <= e; i++ ){
      cout << nodes[i].to << " ";
    } cout << endl;
  }

  for(int i = 1; i <= e; i++){
    if( nodes[i].visited == 0){

      int current = i; 
      while( !nodes[ current ].visited ){
        q_nodes.push_back(current);
        nodes[current].visited = i;
        current = nodes[current].to;
      }

      if( nodes[ current ].visited == i ){
        DEBUG printf("cicle in: %d\n", current); 
        int len = 1;
        for( int temp = current; nodes[temp].to != current; len++ ){
          DEBUG printf("%d \n", temp);
          temp = nodes[temp].to;
        }
        DEBUG printf("len: %d\n", len);

        for( int j = 0; j < len; j++ ){
          DEBUG printf("Removed: %d\n", q_nodes.back());
          nodes[ q_nodes.back() ].steps = len;
          q_nodes.pop_back();
        }

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
