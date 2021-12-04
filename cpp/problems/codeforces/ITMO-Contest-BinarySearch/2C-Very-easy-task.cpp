#include <iostream>
using namespace std;

int n, x, y;

bool good(int t){
  // si el tiempo es menor a ambas impresoras
  if( t<x && t<y ) return false;
  // restamos la copia inicial a la impresora más rápida
  t-=min(x, y);

  return (t/x) + (t/y) +1 >=n;
}

int main(){

  cin >> n >> x >> y;
  int i = 1, f = 2*10e8, m;
  while( i <= f ){
    m = i+(f-i)/2;
    if( good(m) ) f = m-1;
    else i = m+1;
  }
  cout << i;

  return 0;
}
