// 79%
#include <iostream>
#include <stdio.h>
#include <utility>
#include <cmath>
using namespace std;

#define lli long long int
// #define lli float

// #define print printf    // comentar para debugear
template<class... Args>    // no comentar para debugear
void print(Args... args){} // no comentar para debuguear

lli n, m, k, x, y, r, v = 0, mit;
lli a, b, A, B;

lli F(lli x){
  // x--;
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
  lli i=0, f=a*b, v = -1;
  while( i <= f && v == -1){
    mit=(i+f)/2;
    t=F(mit);
    print("%lld: %lld\n", mit, t);
    if(t == k) v=mit;
    else if(t < k) i=mit+1;
    else f=mit-1;
  }
  if(v==-1) v=f;



  // float t;
  // while(true){
  //   t=floor((float)(v)*((float)A+((float)(B-A)/(float)a)));
  //   print("%lld: %f \n", v, t);
  //   // print("%f: %f (%f)\n", v, t, k-t);
  //   if(t==k) {
  //     print("Jutso\n");
  //     v++;
  //     break;
  //   }
  //   if(t >= k) break;
  //   v++;
  // }

  // //cout << min(v, a*b) << endl;

  //v=

  // print("%f\n", (float)k/(A-(float)A/(float)a+(float)B/(float)a));
  // print("%f\n", (float)k/(A+(B-A)/(a)));
  // if(A>k){
  //   cout << 1;
  //   return 0;
  // }
  // v=round((float)k/(A-(float)A/(float)a+(float)B/(float)a));

  // v=k/A;
  // k/=A;
  // //v=v/
  // v+=k*a/B;
  // k/=a/B;
  // v*=k*a/A;

  cout <<min(v+1, a*b) << endl;
  return 0;
}

