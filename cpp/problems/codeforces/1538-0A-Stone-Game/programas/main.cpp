#include <bits/stdc++.h>
using namespace std;

#define r second
#define l first

void game(){
  int n, r; cin >> n;
  vector <int> x(n, 0);
  int m = 0, M = 0;
  for(int i = 0; i < n; i++){
    cin >> x[i];
    if(x[i] == 1) m = i;
    if(x[i] == n) M = i;
  }
  pair <int, int> dm = {m, n-m-1}, a;
  pair <int, int> dM = {M, n-M-1}, b;

  
  if(min(dm.l, dm.r) <= min(dM.l, dM.r)){
    a = m; 
    b = M;
  }else{
    a = M; 
    b = m;
  }
  if(a.l <= a.r){
    printf("Near left\n");
    if()
  }
  else{
    printf("Near right\n");
    r = dm.r + (m-M);
  }

  cout << r << endl;

}

int main(){
  int t;
  cin >> t;
  while (t--) game();
  return 0;
}