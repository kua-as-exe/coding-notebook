#include <bits/stdc++.h>
using namespace std;

int MAX = 1000009; 
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int n, k, ans = 1; cin >> n >> k;
  vector<int> mano(k); for (auto &e : mano) cin >> e;
  sort(mano.begin(), mano.end());

  if (mano[k-1] == mano[0]) { // Entonces es un OMIjuego
    ans = n - mano[0];  
  } else {
    for (int i = 1; i < k; i++) {
      ans *= n; ans %= MAX;
    }
    ans *= (n - mano[k-1]); ans %= MAX;
  }
  ans %= MAX;
  cout << ans;
}