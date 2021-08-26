#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool _debug = false;
#define DEBUG if(_debug)
#define ui unsigned int
#define lli long long int

struct p{
  lli h, w;
};

vector <p> personas;
long int N, n;
unsigned long long int H, h;
long long int W;

int main(){
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  cin >> N >> H;

  personas.resize(N);
  for(int i = 0; i < N; i++){
    cin >> personas[i].h;
    cin >> personas[i].w;
  }

  DEBUG for(int i = 0; i < N; i++)
    cout << personas[i].h << " - " << personas[i].w << endl; 

  ui minMaxW = 0;
  long int i = 0, j = 0;
  lli maxW = personas[i].w, prevMaxW = maxW;
  lli h = personas[i].h;
  
  while( i <= N ){
    if( h >= H ){

        ui maxW = 0;
        for( ui a = i; a <= j; a++ )
          if( personas[a].w > maxW )
            maxW = personas[a].w;
        if ( minMaxW == 0 || maxW < minMaxW ) 
          minMaxW = maxW;

        /* DEBUG printf("From %ld to %ld\n", i, j); */
    }
    if( h < H && j <= N ){ // recorrer fin derecha
      j ++;
      h += personas[j].h;
    } else if( h >= H || j >= N-1 ) { // recorrer inicio
      h -= personas[i].h;
      i++;
    }
  }

  cout << minMaxW;

  return 0;
}
