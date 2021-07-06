#include <bits/stdc++.h>
using namespace std;

int n, m, t, T,N[105], a[105], M[105];
bool have = false;

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> N[i];
  //  cout << N[i] << " ";
  }
  //cout << endl;
  for(int i = 0; i < m; i++){
    cin >> M[i];
    T += M[i];
  }
  //cout << T << endl;
  for(int i = 0; i < n && !have; i++) {
    int x = N[i];
    a[x] ++;
    if(i >= T)
      a[N[i-T]]--;
    
    /* cout << i << ": ";
    for(int j = 0; j <= m; j++)
      cout << a[j] << " "; */
    
    bool si = true;
    for(int j = 0; j <= m; j++){
      //printf("(%d/%d) ", a[j], M[j-1]);
      if( a[j] < M[j-1] ) 
        si = false;
    }

    if(si) have = true;
    
    //cout << endl;
  }
  cout << (have? "YES":"NO");

  return 0;
}