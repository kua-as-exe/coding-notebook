#include <bits/stdc++.h>
using namespace std;
#define Cartas vector<int>
bool debug = true;

int combinaciones = 0;
int N, K, c[1005], m=0;
bool OMIJUEGO = true;

Cartas make_omijuego (int v){
  Cartas omijuego;  
  for(int j = 0; j < K; j++)
    omijuego.push_back(v);
  return omijuego;
}

void print(Cartas cartas){
  if(!debug) return;
  for(int carta : cartas)
    cout << carta << " ";
  bool igual = true;
  for(int i = 1; i < cartas.size(); i++)
    if(cartas[i] != cartas[i-1]) igual = false;
  if(igual) printf("\e[1;34m OMIJuego\e[0m");
  cout << endl;
}

void add(Cartas cartas){
  if(debug) printf("\e[1;34m[%d]\e[0m \t ", combinaciones);
  if(debug) print(cartas);
  combinaciones++;
}

void recurse(Cartas pre){
  int l = pre.size();
  /* printf("\n%d (%s)- ", l, (l < K?"S":"N"));
  print(pre); */
  if( l < K ){
    for(int j = 1; j <= N; j++){
      Cartas t = pre;
      t.push_back(j);
      recurse(t);
    }
  }else
    add(pre);
}

// N - Caracteres
// K - Cantidad de Cartas
int main(){
  cin >> N >> K;
  for (int i = 0; i < K; i++) {
    cin >> c[i];
    if(c[i] > m) m = c[i];
    if(i > 0 && c[i] != c[i-1]) OMIJUEGO = false;
    
  }
  if(debug) {
    for(int i = 0; i < K; i++)
    cout << c[i] << " ";
    cout << endl;
    printf("\e[1;35mMayor: %d\n%s\e[0m\n", m, OMIJUEGO?"Hay omijuego":"No hay omijuego");
  }
  
  int L = N-m;
  if(OMIJUEGO){
    // += [n+1, N] N-m
    for (int i = m+1; i <= N; i++) 
      add(make_omijuego(i));
  }else{
    // += [1, m] + m
    for (int i = 1; i <= m; i++)
      add(make_omijuego(i));

    for(int i = m+1; i <= N; i++){
      Cartas temp = {i};
      recurse(temp);
    }
  }

  if(debug) printf("\e[1;32mTotal: %d\e[0m\n", combinaciones);
  if(!debug) cout << combinaciones%1000009;

  return 0;
}