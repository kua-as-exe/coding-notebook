#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
  long long int n, res = 0; cin >> n;
  unsigned long long int s, sum = 0; cin >> s;

  vector<int> a(n); 
  for( int i = 0; i < n; i++) cin >> a[i];

  for( int j = 0, i = 0; j < n; j++ ){
    sum += a[j];

    while( sum > s )
      sum -= a[i++];
    
    res += j-i+1;
  }

  cout << res;

  return 0;
}
