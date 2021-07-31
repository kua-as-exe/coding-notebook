#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

int espias[1000005];
int lider[1000005];

queue <int> pendientes;

int main(){
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int e, m; cin >> e;
  for(int i = 1; i <= e; i++)
    cin >> espias[i];

  for(int i = 1; i <= e; i++){

    int pasos = 1, j = espias[i];
    /* espias_checked[i] = true; */
    while( lider[j] != i && j != i ){
      printf("(%d) In: %d\n", i, j);

      lider[j] = i;
      j = espias[j];
      pasos++;
    }

    m = max(pasos, m);
    printf("%d: %d\n", i, pasos);

  } 

  cout << m;

  return 0;
}
