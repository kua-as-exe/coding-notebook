#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int f[n];
  for(int i = 1; i <= n; i++)
    cin >> f[i];

  bool x = false;
  for(int a = 1; a <= n; a++){
    int b = f[a];
    int c = f[b];
    if( c != a && c != b){
      printf("%d %d\n", a, c);
      x = true;
    }
  }
  if(!x) cout << "Esto no es tan divertido como parecia";
  
  return 0;
}