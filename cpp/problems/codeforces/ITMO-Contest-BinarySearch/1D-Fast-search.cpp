#include <iostream>
#include <algorithm>
using namespace std;

int main(){

  std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false);

  int n; cin >> n;
  long long int a[n]; for( auto &e : a ) cin >> e;
  sort(a+0, a+n);

  int k, ii, jj; cin >> k;
  while(k--){
    cin >> ii >> jj;

    int li = 0, lf = n - 1, m;
    while (li <= lf) {
      m = (li + lf) / 2;
      if( a[m] >= ii )
        lf = m - 1;+
      else
        li = m + 1;
    }
    int ri = 0, rl = n - 1;
    while (ri <= rl) {
      m = (ri + rl) / 2;
      if( a[m] > jj )
        rl = m - 1;
      else
        ri = m + 1;
    }

    cout << ri - li << " ";
  }

  return 0;
}
