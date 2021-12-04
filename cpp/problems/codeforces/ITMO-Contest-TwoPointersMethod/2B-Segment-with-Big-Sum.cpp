#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
  int n, l = -1; cin >> n;
  long long int s, sum = 0; cin >> s;

  vector<int> a(n); 
  for( int i = 0; i < n; i++) cin >> a[i];

  for( int j = 0, i = 0; j < n; j++ ){
    sum += a[j];

    // avanzar inicio hasta que al quitarlo siga siendo mayor
    while( sum - a[i] >= s )
      sum -= a[i++];

    /* while( sum - a[i] >= s ){ */ 
    /*   sum -= a[i]; */
    /*   i++; */
    /* } */

    /*
    // avanzar inicio hasta que deje de ser mayor y retroceder 1
    while( sum >= s ){ 
      sum -= a[i];
      i++;
    }
    if( i > 0) { i--; sum += a[i]; };
    */

    /* cout << sum << endl; */
    if( sum >= s && ( l == -1 || j-i+1 < l ) )
      l = j-i+1;
  }
  cout << l;

  return 0;
}
