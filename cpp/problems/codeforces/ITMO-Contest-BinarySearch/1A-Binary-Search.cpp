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
    bool founded = false;
    while (i <= f && !founded) {
      m = (i+f)/2;
      if( a[m] == q )
        founded = true;
      else if( a[m] > q ) f = m-1;
      else i = m+1;
    }

    if(founded)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;

  }

  return 0;
}
