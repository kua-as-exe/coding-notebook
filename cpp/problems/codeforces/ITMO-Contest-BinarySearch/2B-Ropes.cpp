#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;

int n, k, r[10005];

bool P(double x){
  int sum = 0;
  for(int i = 1; i <= n; i++ )
    sum += r[i]/x;
  return sum >= k; 
}

int main(){
  cin >> n >> k;
  
  int Max = 0;
  for(int i = 1; i <= n; i++){
    cin >> r[i];
    Max = max(Max, r[i]);
  }
  
  double i = 0, f = Max, m;
  for( int z = 0; z < 100; z++ ){
    m = i+(f-i)/2;
    if( P(m) ) i = m;
    else f = m;
  }
  cout << setprecision(20) << i << endl;
  /* printf("%.20g", i ); */

}
