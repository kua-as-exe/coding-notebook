#include <bits/stdc++.h>
using namespace std;

int n, a[1000], w;

int search(int i, int f){
  if(i == f) return -1;
  int m = (i+f)/2;
  if(w == a[m]) return m;
  if( w > a[m]) return search(m+1, f);
  else return search(i, m);
}

int main(){
  cin >> n;
  for( int i = 0; i < n; i++ ) cin >> a[i];
  cin >> w; 

  cout << search(0, n);

  return 0;
}