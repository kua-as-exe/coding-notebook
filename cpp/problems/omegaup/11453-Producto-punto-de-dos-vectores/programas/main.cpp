#include <iostream>
using namespace std;
int main(){
  int n, ans = 0;
  cin >> n;
  int a[n], b[n];
  for(auto &t : a) cin >> t; 
  for(auto &t : b) cin >> t; 
  for(int i = 0; i < n; i++)
    ans += a[i]*b[i];
  cout << ans;
  return 0;
}