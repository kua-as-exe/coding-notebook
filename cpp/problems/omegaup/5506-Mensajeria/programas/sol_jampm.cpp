#include <bits/stdc++.h>
using namespace std;

int main() {
  bool flag = true; int N, K, x, m = 0, ans = 0; cin >> N >> K;
  while (cin >> x) {
    if (x > K) {
     ans += K; flag = true;
    } else ans += x;
    m = max(x, m);
  }
  if (flag) ans += K - m;
  cout << ans;
}