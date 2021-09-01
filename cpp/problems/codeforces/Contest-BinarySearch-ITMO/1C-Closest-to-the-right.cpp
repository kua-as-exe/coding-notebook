#include <iostream>
using namespace std;

int main(){

  std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false);

  int n, k; cin >> n >> k;
  long long int a[n]; for( auto &e : a ) cin >> e;

  int q;
  while(k--){
    cin >> q;

    int i = 0, f = n-1, m;
    while (i <= f) {
      m = (i+f)/2;
      if( a[m] >= q ) f = m-1;
      else i = m+1;
    }

    cout << i+1 << endl;

  }

  return 0;
}
