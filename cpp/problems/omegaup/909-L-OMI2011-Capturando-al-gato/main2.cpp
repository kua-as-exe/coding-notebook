#include <iostream>
using namespace std;

#define lli long long int
lli n, t, x[5000000];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  cin >> x[0];
  for(int i = 1; i < n; i++){
    cin >> t;
    x[i] = t + x[i-1];
  }

  lli last = x[n-1];
  for(lli k = 1; k <= x[n-1]/2; k++){
    if (last%k == 0){
      lli F = last/k, f = 0;
      for(lli i = 0; i < n && f < F; i++)
        if(x[i]%k == 0)
          f++;
      
      if(f == F){
        cout << f;
        return 0;
      }
    }
  }
  

  cout << 1;
  // cout << "Hola" << endl;
  return 0;
}