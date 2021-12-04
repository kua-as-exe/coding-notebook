#include <iostream> 
#include <stdio.h> 
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

bool _debug = false;
#define DEBUG if( _debug )

const int N = 10e7, M = 10e7;
unsigned int n, m, xMax, i, j, k, acc, l, r, sum, Pl, Pr, ini, fin, mit, res;

vector <unsigned int> x, primes, 
       primes_f_acc, 
       not_prime;
vector <pair <unsigned int, unsigned int> > queries;

int main(){

  cin >> n;
  x.resize(n);
  for( i = 0; i < n; i++ ) {
    cin >> x[i];
    DEBUG printf("%2d ", x[i]);
  }; DEBUG cout << endl;
  
  cin >> m;
  queries.resize(m);
  for( i = 0; i < m; i++){
    cin >> queries[i].first >> queries[i].second;
    if( queries[i].second > 10e7 ) queries[i].second = 10e7;
    xMax = max(xMax, queries[i].second);
  }

  DEBUG printf("MAX: %d\n", xMax);
  
  not_prime.resize(xMax);
  for( i = 2; i < xMax; i++ ){
    if( !not_prime[i] ){
      DEBUG printf("Founded prime: %d -> ", i);
      
      sum = 0 ;
      if( sum == 0 ){
        for( k = 0; k < n; k++ ){
          if( x[k]%i == 0 ){
            DEBUG printf("%d ", x[k]);
            sum++;
          }
        } DEBUG printf("(%d)", sum);
      }
      /* primes_f.push_back(sum); */
      
      acc = sum;
      if( !primes_f_acc.empty() )
        acc += primes_f_acc.back();
      primes_f_acc.push_back( acc );

      for( j = i*2; j < xMax; j+=i )
        not_prime[j] = true;

      DEBUG cout << endl;
    }
  }


  for( auto query : queries ){
    l = query.first; r = query.second;
    
    Pl =-1, Pr = -1;
    bool l_founded = false, r_founded = false;
    ini = 0, fin = primes.size()-1, mit = 0;
    while( ini <= fin && !l_founded ){
      mit = ini+(fin-ini)/2;
      if( primes[mit] == l ) {
        Pl = mit; l_founded = true;
      }
      else if( primes[mit] > l ) fin = mit-1;
      else ini = mit+1;
    }
    if(!l_founded) Pl = ini-1;

    ini = 0, fin = primes.size()-1, mit = 0;
    while( ini <= fin && !r_founded ){
      mit = ini+(fin-ini)/2;
      if( primes[mit] == r ) {
        Pr = mit; r_founded = true;
      }
      else if( primes[mit] > r ) fin = mit-1;
      else ini = mit+1;
    }
    if(!r_founded) Pr = ini-1;

    DEBUG printf("[%d - %d] (%d, %d)\n", l, r, Pl, Pr);

    if( !l_founded && !r_founded ) {
      cout << 0 << endl;
      continue;
    }

    DEBUG {
      for( i = Pl; i <= Pr; i++) printf("%2d ", primes[i]); cout << endl;
      /* for( i = Pl; i <= Pr; i++) printf("%2d ", primes_f[i]); cout << endl; */
      for( i = Pl; i <= Pr; i++) printf("%2d ", primes_f_acc[i]); cout << endl;
    }

    res = primes_f_acc[Pr];
    if( Pl > 0 ) res -= primes_f_acc[Pl-1];
  
    cout << res << endl;
    continue;
  }

  return 0;
}
