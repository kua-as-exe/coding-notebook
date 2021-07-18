// AC
#include <bits/stdc++.h>
using namespace std;

// par, impar
pair<int, int> M[5005];
int caminos[5005][5005];
int n, m, p;

// pair: x, k
queue < pair<int, int> > nodes;
int x, k;

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int t, t2;
    cin >> t >> t2;
    caminos[t][t2] = 1;
    caminos[t2][t] = 1;
  }

  nodes.push({1, 1});
  while( !nodes.empty() ){
    pair <int, int> f = nodes.front();
    x = f.first;
    k = f.second;

    nodes.pop();
    for(int i = 1; i <= n; i++){
      if(caminos[x][i] == 1){
        if(M[i].first != 0 && M[i].second != 0)
          continue;
        if( k%2 == 0 && M[i].first == 0){
          M[i].first = k;
          nodes.push({ i, k+1 });
        }
        if( k%2 != 0 && M[i].second == 0){
          M[i].second = k;
          nodes.push({ i, k+1 });
       }
      }
    }
  }

  cin >> p;
  for(int i = 0; i < p; i++){
    cin >> x >> k;
    if(
        ( x == 1 && k == 0 ) || // Special case, first position without no steps is valid
        ( k%2 == 0 && M[x].first > 0 && M[x].first <= k ) || // if even steps and node is accessible
        ( k%2 != 0 && M[x].second > 0 && M[x].second <= k ) // if odd steps and node is accessible
      )
      cout << 1;
    else
      cout << 0;
    cout << endl;
  }
}
