#include <bits/stdc++.h>
using namespace std;
bool d = false;

int main(){
  int n; cin >> n;

  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];

  if(d) for(int i = 0; i < n; i++) cout << a[i] << " ";
  if(d) cout << endl;
  int w; cin >> w;
  if(d) cout << w << endl;

  int i=0, f=n, m, pos=-1;
  while( i != f && pos == -1){
    m = (i+f)/2;
    if(a[m] == w) pos = m; 
    if(w > a[m]) i = m+1;
    else f = m;
  }
  cout << pos;
  return 0;
}