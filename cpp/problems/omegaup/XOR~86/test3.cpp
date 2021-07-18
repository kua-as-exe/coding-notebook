#include <bits/stdc++.h>
using namespace std;

long long int n, t, c, x[100000];

long long int range(int s, int e) {
    t = x[e];
    if (s > 0) t ^= x[s - 1];
    return t;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> x[0];
    for (int i = 1; i < n; i++) {
        cin >> x[i];
        x[i] ^= x[i - 1];
    }

    for (int l = n - 1; l >= 1; l--) {
        for (int k = 0; k < n - l; k++) {
            if (range(k, k + l) == 0) {
                c++;
            }
        }
    }

    cout << c;
    return 0;
}
