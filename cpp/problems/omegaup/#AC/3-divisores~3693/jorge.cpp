#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  long double p, q; 
  cin >> p >> q; 
  long long int top = ceil(sqrt(q));
  vector<bool> esprimo(top, true); 
  int ans = 0;
  for (long long int i = 2; i < top; i++) {
    if (esprimo[i]) {
      long long int k = i*i; 
      if (k < q && k > p) ans++;
      for (long long int j = 2; j*i < top; j++) 
        esprimo[j*i] = false;
    }
  }
  cout << ans;
}
