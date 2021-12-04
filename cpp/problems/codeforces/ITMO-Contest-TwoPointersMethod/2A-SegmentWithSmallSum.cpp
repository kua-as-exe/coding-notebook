#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
  int n, l = 0; cin >> n;
  unsigned long long int s, sum = 0; cin >> s;

  vector<int> a(n); 
  for( int i = 0; i < n; i++) cin >> a[i];

  for( int j = 0, i = 0; j < n; j++ ){
    sum += a[j];

    while( i < j && sum > s ){
      sum -= a[i];
      i++;
    }

    if( sum <= s )
      l = max(l, j-i+1);
  }

  cout << l;

  return 0;
}
