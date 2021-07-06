#include <iostream>
using namespace std;
int main(){
  int n, k;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  cin >> k;

  for(int i = 0; i < n; i++){
    if(a[i]%k ==0) cout << a[i];
    else cout << 'X';
    if(i < n-1) cout << ' ';
  }

  return 0;
}