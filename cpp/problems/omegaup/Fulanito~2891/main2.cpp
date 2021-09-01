#include <bits/stdc++.h>
using namespace std;

long long int L = 1e9;
long long int a[100005], t, q, n;

int main(){

  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  cin >> q >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if( i > 0 )
      a[i] = a[i] + a[i-1];
  }

  while(q--){
    /* scanf("%lld", &t); */
    cin >> t;
    long long int ii=0, f=n-1, m;
    while( ii<=f && ii<n ){
      m=(ii+f)/2;
      //printf("%d\n",m);
      if( a[m] > t) f = m-1;
      else ii = m+1;
    }
    printf("%lld %lld\n", ii, t-a[ii-1]);
  }

  return 0;
}
