#include <bits/stdc++.h>
using namespace std;

#define ll int long long

ll mcd(ll a, ll b){
  if(b == 0) return a;
  return mcd(b, a%b);
}
ll mcm(ll a, ll b){
  return a*b/mcd(a, b);
}

int main(){
  ll m, n, 
      a, d, 
      f, c;
  cin >> m >> n;
  cin >> a >> d;
  cin >> f >> c;

  cout << mcm( mcm(m, a)/a, mcm(n, d)/d );
  return 0;
}