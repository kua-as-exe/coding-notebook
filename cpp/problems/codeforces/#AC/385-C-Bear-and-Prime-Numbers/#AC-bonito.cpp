#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = 1e7;

int main(){
  int n, m, i, j, l, r, t;

  vector<int> x(N), pre(N), primes;
  vector<bool> is_prime(N, true);

  std::ios_base::sync_with_stdio(false); 
  std::cin.tie(0); std::cout.tie(0);

  cin >> n;
  for( i = 0; i < n; i++ ) {
    cin >> t; x[t]++;
  }; 
  
  for( i = 2; i < N; i++ ){
    if( !is_prime[i] ) continue;

    primes.push_back(i);

    if( i < sqrt(N) )
      for( j = i*2; j <= N; j+=i )
        is_prime[j] = false;

  }

  for( int p : primes )
    for( i = p; i <= N; i+=p )
      pre[p] += x[i];
  
  for( i = 1; i <= N; i++ )
    pre[i] += pre[i-1];

  cin >> m;
  while(m--){
    cin >> l >> r;

    r = min( r, N );
    l = min( l, N );
  
    cout << pre[r]-pre[l-1] << endl;
  }

  return 0;
}
