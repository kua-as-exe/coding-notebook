#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool _debug = false;
#define DEBUG if(_debug)
#define ui unsigned int

struct p{
  long long int h, w;
};

vector <p> personas;
long int N, n;
unsigned long long int H, h;
long long int W;

int main(){
  cin >> N >> H;

  personas.resize(N);
  for(int i = 0; i < N; i++){
    cin >> personas[i].h;
    cin >> personas[i].w;
  }

  DEBUG for(int i = 0; i < N; i++){
    cout << personas[i].h << ": " << personas[i].w << endl; 
  }

  ui minMaxW = 0;
  for(ui a = 0; a < N; a++){
    for( ui l = 1; l <= N-a; l++ ){
      ui count = 0;
      ui maxW = 0;
      for( ui i = a; i <= a+l-1; i++ ){
        count += personas[i].h;
        if( personas[i].w > maxW ) maxW = personas[i].w;
        if( count >= H )
          break;
      }
      if( count >= H ){
        if ( minMaxW == 0 || maxW < minMaxW ) minMaxW = maxW;
      }
    }
  }

  cout << minMaxW;

  return 0;
}
