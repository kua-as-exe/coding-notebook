#include <iostream>
using namespace std;
int main(){
  int n, flag = 1;
  cin >> n;
  
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  int t;
  for(int i = 0; i < n; i++) {
    cin >> t;
    if(a[i] <= t) flag = 0;
  }

  cout << flag;

  return 0;
}