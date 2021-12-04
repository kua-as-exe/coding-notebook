#include <iostream>
#include <vector>
using namespace std;

int main(){

  int n; cin >> n; vector<long long int> a(n);
  long long int sum, s, res=0; cin >> s;

  for(int i = 0; i < n; i++)
    cin >> a[i];

  for(int i = 0, j = 0; j < n; j++){
    sum += a[j];
  
    while( sum - a[i] >= s )
      sum -= a[i++];
    /* cout << i << " " << j << " " << sum << endl; */

    if( sum >= s )
      res += j-i+1;
    
  }

  cout << (n*(n-1))/2-res-1;

  return 0;
}
