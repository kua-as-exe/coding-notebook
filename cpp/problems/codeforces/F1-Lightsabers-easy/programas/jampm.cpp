#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int n, m, aux; cin >> n >> m; 
  vector<int> expected(m, 0);
  while (--n) {
    cin >> aux;
    expected[aux]++;
  }
  for (int i = 0; i < m; i++) {
    cin >> aux;
    if (expected[i] < aux) {
     cout << "NO";
     return 0;
    }
  }
  cout << "YES";
}
