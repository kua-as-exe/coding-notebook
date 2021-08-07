#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

bool debug = false;
#define DEBUG if( debug )

int espias[1000005];
int lider[1000005];
int e_pasos[1000005];

queue <int> pendientes;

int main(){
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int e, m; cin >> e;
  for(int i = 1; i <= e; i++)
    cin >> espias[i];

  for(int i = 1; i <= e; i++){

    int pasos = 1, j = espias[i];
    if( lider[i] ){
      pasos = e_pasos[i];
    }else {
      DEBUG printf("\nFor %d:\n", i);
      while( lider[j] != i && j != i ){
        if( e_pasos[j] ){
          DEBUG printf("Founded %d\n", e_pasos[j]);
          pasos += e_pasos[j];
          break;
        }
        pendientes.push(j);
        DEBUG printf("[%d]", j);
        lider[j] = i;
        j = espias[j];
        pasos++;
      }
      while( !pendientes.empty() ){
        e_pasos[ pendientes.front() ] = pasos;
        pendientes.pop();
      }
    }
    e_pasos[i] = pasos;
    DEBUG printf("Pasos: %d\n", pasos);
    m = max(pasos, m);

  } 

  cout << m-1;

  return 0;
}

