#include <bits/stdc++.h>
using namespace std;

long long int n, v[100005], last, ans, temp, i;
long long int M = 1000000007;

int main(){
  cin >> n;
  for(i = 0; i < n; i++)
    cin >> v[i];
  sort(v+0, v+n);

  last = 0;
  temp = 0;
  for(i = 0; i < n; i++){
    if(v[i] > last){
      last = v[i];
      temp = ans;
    }    
    ans += temp % M;
    ans += 1 % M;
  }
  
  cout << ans;
  return 0;
}