#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  long double n, m; cin >> n >> m; ll M = ceil(sqrt(m));
  vector<bool> esprimo(M, true); int ans = 0;
  for (ll i = 2; i < M; i++) {
    if (esprimo[i]) {
      ll k = i*i; if (k < m && k > n) ans++;
      for (ll j = 2; j*i < M; j++) esprimo[j*i] = false;
    }
  }
  cout << ans;
}