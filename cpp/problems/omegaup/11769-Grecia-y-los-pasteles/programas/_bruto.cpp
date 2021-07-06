#include <bits/stdc++.h>
using namespace std;

long long int n, t, v[100005], last, ans, temp;
long long int M = 1000000007;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> v[i];
  sort(v+0, v+n);

  for(int i = 0; i < n; i++){
    // for(int j = 0)
    ans += (temp+1) % M;
  }
  
  cout << ans;
  return 0;
}