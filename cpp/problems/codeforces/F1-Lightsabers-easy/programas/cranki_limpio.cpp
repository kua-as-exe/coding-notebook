#include <bits/stdc++.h>
using namespace std;

int n, m, t, T,N[105], a[105], M[105];
bool have = false;

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) 
    cin >> N[i];

  for(int i = 0; i < m; i++){
    cin >> M[i];
    T += M[i];
  }

  for(int i = 0; i < n && !have; i++) {
    int x = N[i];
    a[x] ++;
    if(i >= T)
      a[N[i-T]]--;

    bool si = true;
    for(int j = 0; j <= m; j++)
      if( a[j] < M[j-1] ) 
        si = false;
  
    if(si) have = true;
  }
  cout << (have? "YES":"NO");
  return 0;
}