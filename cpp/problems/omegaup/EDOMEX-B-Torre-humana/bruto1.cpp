#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool _debug = false;
#define DEBUG if(_debug)

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

  sort(personas.begin(), personas.end(), [](p p1, p p2){ return p1.w < p2.w; });

  DEBUG for(int i = 0; i < N; i++){
    cout << personas[i].h << ": " << personas[i].w << endl; 
  }

  while( true ){
    h += personas[n].h;
    W = personas[n].w;
    n++;
    if( h >= H ) break;
  }
  cout << W;

  return 0;
}
