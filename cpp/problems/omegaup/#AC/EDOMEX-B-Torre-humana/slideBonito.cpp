#include <iostream>
#include <vector>
using namespace std;

vector <long long int> h_list, w_list;
long int N;
long long int H, h, W;

int main(){
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  cin >> N >> H;

  h_list.resize(N);
  w_list.resize(N);
  for(int i = 0; i < N; i++){
    cin >> h_list[i];
    cin >> w_list[i];
  }

  long int minMaxW = 0;
  long int i = 0, j = 0;
  long long int maxW = w_list[i], prevMaxW = maxW, h = h_list[i];
  
  while( i <= N ){
    if( h >= H ){

        int maxW = 0;
        for( int a = i; a <= j; a++ )
          if( w_list[a] > maxW )
            maxW = w_list[a];
        if ( minMaxW == 0 || maxW < minMaxW ) 
          minMaxW = maxW;

    }
    if( h < H && j <= N ){ // recorrer fin derecha
      j ++;
      h += h_list[j];
    } else if( h >= H || j >= N-1 ) { // recorrer inicio
      h -= h_list[i];
      i++;
    }
  }

  cout << minMaxW;

  return 0;
}
