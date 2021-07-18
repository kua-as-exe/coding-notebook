#include <iostream>
#include <algorithm>
using namespace std;
int a[55], b[55], bi = 0;
int main(){
  int n;
  cin >> n;
  int t;
  for(int i = 0; i < n; i++){
    cin >> t;
    if(a[t] == 0)
      b[bi++] = t;
    a[t] ++;
  }
  sort(b+0, b+bi);
  for(int i = 0; i < bi; i++)
    printf("%d %d\n", b[i], a[b[i]]);

  return 0;
}