// AC
#include <stdio.h>

long long int n, m, x, y, k, v, t, pisos;

int main(){
  scanf("%lld %lld %lld %lld %lld", &n, &m, &k, &x, &y);

  // invertir si es necesario
  if(x>y){ 
    t=y; y=x; x=t; 
    t=m; m=n; n=t;
  } 

  // B+A*(a-1) -> Costo por piso
  pisos = k/(y+x*(m-1));
  if(pisos > n-1) pisos = n-1;
  if(pisos > 0){
    v += pisos*m;
    k -= pisos*(m-1)*x + (pisos)*y;
  }
  v += (k/x < m-1)? k/x : m-1;
 
  printf("%lld", v+1);
  return 0;
}
