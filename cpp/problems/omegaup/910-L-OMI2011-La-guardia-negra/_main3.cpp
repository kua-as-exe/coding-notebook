#include <stdio.h>

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

  scanf("%d %d", &m, &n);
  for(int i = 0; i < m; i++){
    scanf("%lld", &xx[i][0]);
    for(int j = 1; j < n; j++){
      scanf("%lld", &xx[i][j]);
      xx[i][j] += xx[i][j-1];
    } 
  }

  scanf("%lld", &p);
  while(p--){
    
    scanf("%d %d %d", &x, &y, &d);
    lli sumaTotal = 0;

    for(int a = 0; a < d; a++){
      sumaTotal += suma(x-d+a, y-a, y+a);
      sumaTotal += suma(x+a+1, y-d+a+1, y+d-a-1);
    }

    sumaTotal += suma(x, y-d, y+d);

    printf("%lld\n", sumaTotal);
  }

  return 0;
}