#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, t;
  cin >> n >> m;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(i > 0) 
      a[i] += a[i-1];
  }
  /* for(int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl; */
  
  for(int j = 0; j < m; j++){
    cin >> t;

    int i=0, f=n-1;
    while(i!=f){
      int M=(i+f)/2;
      if( a[M] < t) i = M+1;
      else f = M;
    }
    cout << i+1;
    if(j < m-1) cout << " ";
  }

  return 0;
}