#include <bits/stdc++.h>
using namespace std;

#define value first
#define pos second

bool myfunction (pair<int, int> i, pair<int, int> j) { 
  return (i.value < j.value); 
}

int main(){
  int N, K, centrales = 0; 
  cin >> N >> K;

  vector <pair<int, int>> c_o(N);

  int t;
  for (int i = 0; i < N; i++) {
    cin >> t;
    c_o[i] = {t, i};
  }

  //sort(c_o.begin(), c_o.end(), myfunction);

/*   for( auto i : c) cout << i << ", "; cout << endl; */
  /* for( auto i : c_o) cout << i.value << ", "; cout << endl;
  for( auto i : c_o) cout << i.pos << ", "; cout << endl; */

  int m = 0;
  int ans = 0;
  for(auto c : c_o){
    if( K < c.value){
      //printf("%d vs %d\n",  c.value, K);
      //c_o[i].value = 0;
      //centrales ++;
      //printf("+%d\n", K);
      ans += K; 
    }else {
     //printf("+%d\n", c.value);
     ans += c.value;
    };
    m = max(x, m);
  }
  //printf("centrales: %d\n", centrales);
  //for(int i = 0; i < c_o.size()-centrales-1; i++)
   
  //printf("envios: %d\n", ans);
  cout << ans;
  
  return 0;
}