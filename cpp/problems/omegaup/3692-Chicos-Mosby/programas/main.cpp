#include <bits/stdc++.h>
using namespace std;

long long int n, m, i;

int main(){
  cin >> n >> m;
  while( n > 1 && m > 1){
    if(n < m){
      i += m/n;
      m %= n;
    }
    else{
      i += n/m;
      n %= m;
    }
  }

  if(n == 1)
    i += m;
  if(m == 1)
    i += n;

  cout << i;
  return 0;
}