#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool _debug = false;
#define DEBUG if( _debug )

const int N = 1e7;
int n, m, i, j, l, r, t;

int x[10000001], pre[10000001];
bool not_prime[10000001];

vector<int> primes;

int main(){

  std::ios_base::sync_with_stdio(false); 
  std::cin.tie(0); std::cout.tie(0);

  cin >> n;
  for( i = 0; i < n; i++ ) {
    cin >> t; 
    x[t]++;
  }; 
  
  for( i = 2; i < N; i++ ){
    if( !not_prime[i] ){
      primes.push_back(i);

      if( i < sqrt(N) )
        for( j = i; j <= N; j+=i )
          not_prime[j] = true;

    }
  }

  for( int p : primes )
    for( i = p; i <= N; i+=p )
      pre[p] += x[i];
  
  for( i = 1; i <= N; i++ )
    pre[i] += pre[i-1];

  cin >> m;
  while(m--){
    cin >> l >> r;

    if( l >= N ){
      cout << 0 << endl;
      continue;
    }

    r = min( r, N );
  
    cout << pre[r]-pre[l-1] << endl;
  }

  return 0;
}
