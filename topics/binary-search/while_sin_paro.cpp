#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int a[n-1];
  for(int i = 0; i < n; i++) cin >> a[i];

  int w; cin >> w;

  int i=0, f=n, m;
  while( i != f ){
    m = (i+f)/2;
    if(w > a[m]) i = m+1;
    else f=m;
  }
  if(a[i] == w) cout << i;
  else cout << -1;
}