#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int MAX = 1000009;
int N, K, mayor;
bool OMIJuego = true;

int main(){
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  cin >> N >> K;

  pair <int, int> cartas; // [pasado, actual]
  for (int i = 0; i < K; i++)
  {
    cin >> cartas.second;
    if( OMIJuego && i > 0 && cartas.second != cartas.first ) OMIJuego = false;
    if( cartas.second > mayor || i == 0) mayor = cartas.second;
    cartas.first = cartas.second;
  }

  if(OMIJuego) cout << N-mayor;
  else{
    int potencias = 1;
    for (int i = 1; i < K; i++) // pow
      potencias = (N*potencias)%MAX; 
    
    cout << (N-mayor)*potencias%MAX;
  }
  return 0;
}