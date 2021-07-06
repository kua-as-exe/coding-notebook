// 79%
#include <iostream>
#include <stdio.h>
#include <utility>
using namespace std;

#define lli long long int

// #define print printf    // comentar para debugear
template<class... Args>    // no comentar para debugear
void print(Args... args){} // no comentar para debuguear

lli n, m, k, x, y, r, v = 0;
lli a, b, A, B;

lli f(lli x){
  x--;
  return x*A+(B-A)*(x/a);
  // return x*A+x*(B-A)/a;
}

int main(){
  cin >> n >> m >> k >> x >> y;
  print("\nn\tm\tk\tx\ty\n");
  print("%lld\t%lld\t%lld\t%lld\t%lld\n", n, m, k, x, y);
  
  if(x<y){ a=m; A=x, b=n; B=y; } 
  else { a=n; A=y, b=m; B=x; } 
 
  // for(int i = 0; i <= 20; i++)
  //   print("%d: %lld\n", i, f(i));
  
  lli t;
  while(true){
    t=f(v+1);
    print("%lld: %lld (%lld)\n", v+1, t, k-t);
    if(t==k) {
      print("Jutso\n");
      v++;
      break;
    }
    if(t >= k) break;
    v++;
  }

  cout << min(v, a*b) << endl;
  return 0;
}

