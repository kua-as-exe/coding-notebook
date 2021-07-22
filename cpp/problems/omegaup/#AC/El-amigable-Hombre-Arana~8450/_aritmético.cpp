// AC
#include <iostream>
#include <stdio.h>
#include <utility>
using namespace std;

#define lli long long int
lli n, m, x, y, k, v, t, pisos;

int main(){
  scanf("%lld %lld %lld %lld %lld", &n, &m, &k, &x, &y);
  // cin >> n >> m >> k >> x >> y;
  
  // invertir si es necesario
  if(x>y){ 
    t=y; y=x; x=t; 
    t=m; m=n; n=t;
  } 

  // B+A*(a-1) -> Costo por piso
  pisos = min(k/ (y+x*(m-1)) , n-1);
  if(pisos > 0){
    v += pisos*m;
    k -= pisos*(m-1)*x + (pisos)*y;
  }
  v += min(k/x, m-1);
 
  printf("%lld", v+1);
  return 0;
}
