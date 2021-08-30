#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool _debug = false;
#define DEBUG if(_debug)
#define ui unsigned int
#define lli long long int

/* struct p{ */
/*   lli h, w; */
/* }; */

/* vector <p> personas; */
vector<lli> alturasAcomuladas;
vector<lli> pesos;
long int N, n;
unsigned long long int H, h;
long long int W;

int main(){
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  cin >> N >> H;

  /* personas.resize(N); */
  alturasAcomuladas.resize(N);
  pesos.resize(N);
  for(int i = 0; i < N; i++){
    cin >> alturasAcomuladas[i];
    cin >> pesos[i];
    if( i > 0 )
      alturasAcomuladas[i] += alturasAcomuladas[i - 1];
  }

  DEBUG for (int i = 0; i < N; i++) cout
      << pesos[i] << "(" << alturasAcomuladas[i]
      << "): " << alturasAcomuladas[i] << endl;

  lli minMaxW = 0;
  for(ui a = 0; a < N; a++){
    for( ui l = 1; l <= N-a; l++ ){
      ui count = alturasAcomuladas[a + l - 1];
      if( a > 0 )
        count -= alturasAcomuladas[a - 1];
      if( count >= H ){
        /* ui maxW = 0; */
        /* for( ui i = a; i <= a+l-1; i++ ) */
        /*   if( pesos[i] > maxW ) */
        /*     maxW = pesos[i]; */
        lli maxW = *max_element(pesos.begin()+a, pesos.begin()+a+l);
        if ( minMaxW == 0 || maxW < minMaxW ) 
          minMaxW = maxW;
      } 
    }
  }

  cout << minMaxW;

  return 0;
}
