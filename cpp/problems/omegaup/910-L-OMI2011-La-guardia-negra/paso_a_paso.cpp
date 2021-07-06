#include <bits/stdc++.h>
using namespace std;

#define lli long long int

int n, m, d, x, y,  i, j, f;
lli xx[1005][1005], p, s;

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
      // cout << xx[i][j] << "\t";
    } 
    // cout << endl;
  }

  cin >> p;
  while(p--){
    printf("\n");

    cin >> x >> y >> d;
    lli sumaTotal = 0;
    printf("Para: %d %d %d\n", x, y, d);
    for(int a = 0; a < d; a++){
      printf("%d | ", a);
      // Los de arriba
      i = y-a;
      j = y+a;
      f = x-d+a;
      s = suma(f, i, j);
      sumaTotal += s;
      printf("↑%d -> %d-%d: %lld\t", f, i, j, s);

      // Los de Abajo
      i = y-d+a+1;
      j = y+d-a-1;
      f = x+a+1;
      s = suma(f, i, j);
      printf("↓%d -> %d-%d: %lld\n", f, i, j, s);
      sumaTotal += s;
    }

    i = y-d;
    j = y+d;
    f = x;
    s = suma(f, i, j);
    printf("~%d -> %d-%d: %lld\n", f, i, j, s);
    sumaTotal += s;

    printf("Suma: %lld\n", sumaTotal);
    printf("\n");
    // cout << sumaTotal << "\n";
  }

  return 0;
}