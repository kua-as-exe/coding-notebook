#include <bits/stdc++.h>
using namespace std;

int x[100];

int main(){
  int n, t, k; 
  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> x[i];

  cin >> k;

  for(int j = 0; j < n; j++){
    cout << x[j] << ", ";
  } cout << endl;

  int ini = 0, fin = n-1, m = 0;

  if( k > x[fin] ){ cout << -1; return 0; }
  if( k < x[ini] ){ cout << -1; return 0; }

  while( ini != fin ){
    m = (ini+fin)/2;
    if( x[m] < k ) ini = m+1;
    else fin = m;
  }
  cout << ini;

  return 0;
}
