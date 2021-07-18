#include <bits/stdc++.h>
using namespace std;

#define lli long long int

int n, m, d, x, y;
lli xx[1005][1005], p;

lli suma(int f, int i, int j){
  if(f < 0 || f >= m) return 0;
  if(i < 0 || j < 0 ) return 0;
  
  lli s = (j < n)? xx[f][j]: xx[f][n-1];
  if( i > 0 ) 
    s -= xx[f][i-1];
  return s;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> m >> n;
  for(int i = 0; i < m; i++){
    cin >> xx[i][0];
    for(int j = 1; j < n; j++){
      cin >> xx[i][j];
      xx[i][j] += xx[i][j-1];
    } 
  }

  cin >> p;
  while(p--){
    
    cin >> x >> y >> d;
    lli sumaTotal = 0;

    for(int a = 0; a < d; a++){
      sumaTotal += suma(x-d+a, y-a, y+a); // arriba
      sumaTotal += suma(x+a+1, y-d+a+1, y+d-a-1); // abajo
    }

    sumaTotal += suma(x, y-d, y+d); // centro

    cout << sumaTotal << "\n";
  }

  return 0;
}