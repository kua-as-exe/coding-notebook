#include <iostream>
#include <deque>
using namespace std;

long int N;
long long int h_list[100005], w_list[100005];
long long int H, h, W;

int main(){
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  cin >> N >> H;

  for(int i = 0; i < N; i++){
    cin >> h_list[i];
    cin >> w_list[i];
  }

  long long int minMaxW = 1e9+1; // establecemos el mínimo como un valor más grande de lo posiblE

  deque<int> Qi(N);

  // inicializamos los valores necesarios ( primer elemento de la deque, el primer peso y la primera altura )
  Qi.push_back(0);
  long long int h = h_list[0];

  long int i = 0, j = 0; // comenzamos la slide window en [0, 0]
  while( i <= N ){
    if( h >= H )
      // si hay una slide peso mayor más pequeño que los anteriores, actualizar el peso menor
      minMaxW = min( minMaxW, w_list[ Qi.front() ] );
    
    if( h < H && j <= N ){ // recorrer fin derecha
      j ++;
      h += h_list[j]; // sumar la altura de la nueva persona
      
      while( !Qi.empty() && w_list[j] >= w_list[  Qi.back() ] )
        Qi.pop_back(); // quitar los pesos más pequeños

      Qi.push_back(j); // añadir el nuevo peso más grande

    } else if( h >= H || j >= N-1 ) { // recorrer inicio
      h -= h_list[i]; // restar la altura de la persona anterior

      while( !Qi.empty() && Qi.front() <= i ) 
        Qi.pop_front(); // quitar los pesos fuera de la slide

      i++;
    }
  }

  cout << minMaxW;

  return 0;
}
