#include <bits/stdc++.h>
using namespace std;

long long L = 1e9;
long long int a[100005], t, q, n;

int main(){
  cin >> q >> n;
  cin >> a[0];
  for(int i = 1; i < n; i++){
    cin >> a[i];
    a[i] = a[i] + a[i-1]%L;
  }

  while(q--){
    cin >> t;
    long long int i=0, f=n, m, pos = -1;
    while( i<=f && i<n && pos==-1){
      m=(i%L+f%L)/2;
      //printf("%d\n",m);
      //if( a[m] == t ) pos = m;
      if( a[m] > t) f = m-1;
      else i = m+1;
    }

    printf("%lld %lld\n", i, t-a[i-1]);
    /* if(pos >= 0)
       printf("%lld %lld\n", pos+1, t-a[pos]);
       else {
       if(i > 0)
       else
       printf("%lld %lld\n", i, a[n-1]);
       } */
  }

  return 0;
}
