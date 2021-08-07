// 1.49s
#include <stdio.h>
#include <vector>
using namespace std;

/* #define DEBUG if( false ) */

int to[1000005], steps[1000005], visited[1000005];

vector<int> q;

int main(){
  int e; scanf("%d", &e);
  for(int i = 1; i <= e; i++)
    scanf("%d", &to[i]);

  for(int i = 1; i <= e; i++){
    if( visited[i] == 0){

      int current = i; 
      while( !visited[ current ] ){
        q.push_back(current);
        visited[current] = i;
        current = to[current];
      }

      if( visited[ current ] == i ){
        /* DEBUG printf("cicle in: %d\n", current); */ 
        int len = 1;
        for( int temp = current; to[temp] != current; len++ ){
          /* DEBUG printf("%d \n", temp); */
          temp = to[temp];
        }
        /* DEBUG printf("len: %d\n", len); */

        for (int j = 0; j < len && !q.empty(); j++) {
          /* DEBUG printf("Removed: %d\n", q.back()); */
          steps[q.back()] = len;
          q.pop_back();
        }
      }

      while (!q.empty()) {
        steps[q.back()] = steps[to[q.back()]] + 1;
        q.pop_back();
      }
    }
  }

  /* DEBUG printf("This is the end\n"); */
  int max = 0;
  for( int i = 1; i <= e; i++ ){
    /* DEBUG printf("%d: %d\n", i, steps[i]); */
    if( steps[i] > max ) max = steps[i];
  }
  printf("%d", max);

}
