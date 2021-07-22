
#include <iostream>
using namespace std;

int main() {

  int n; cin >> n;
  int p, c, d = 1, m = 0;

  cin >> p;
  for(int i = 1; i < n; i++){
    cin >> c;
    if( c >= p ){
      if( d > m ) m = d;
      d = 0;
    }
    d++;
    
    if( i == n-1 && d > m ) m = d;
    p = c;
  }
  cout << m;

  return 0;
}
