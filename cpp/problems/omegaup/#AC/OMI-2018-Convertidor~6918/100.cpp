#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int o = 0, c = 26;
  cin >> o;

  if ( o == 0 ){
    long long int x; 
    cin >> x;
    string t = "";
    while ( x > 0 ){
      char chr = 'A';
      if( x%c == 0 ){
        chr = 'Z';
        x--;
      } else {
        chr = (x%c + 'A'-1 );
      }
      /* printf("%lld - %lld ~ %c\n", x, x%c, chr); */
      t = chr+t;
      x = x/c;
    }
    cout << t;
  }else {
    string t; cin >> t;
    long long int x = 0;
    for(int i = 0; i < t.size(); i++){
      long long int k =  pow(26, t.size()-i-1 ) ;
      /* printf("%c - %d - %d - %lld\n", t[i], t[i]-'A'+1, (int)t.size()-1-i, k); */
      x += ( (int)t[i]-'A'+1)*(k);
    }
    cout << x;
  }


  return 0;
}
