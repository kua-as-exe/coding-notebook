#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, a, b;
  cin >> n;
  double x[n];
  for(int i = 0; i < n; i++){
    cin >> x[i];
    if( i > 0 )
      x[i] += x[i-1];
  }
  cin >> m;
  while(m--){
    cin >> a >> b;
    if( a > 0)
      cout << x[b] - x[a-1] << endl;
    else cout << x[b] << endl;
  }
  return 0;
}