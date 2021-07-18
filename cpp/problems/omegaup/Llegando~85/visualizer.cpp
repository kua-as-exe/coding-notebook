#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define queueColumns  5
#define delay 0.7 // seconds

#define RES "\u001b[0m"
#define RED "\u001b[31m"
#define GRE "\u001b[32m"
#define YEL "\u001b[33m"
#define BRI_WHI "\u001b[37;1m"

// par, impar
pair<int, int> M[5005];
int caminos[5005][5005];
int n, m, p;

// pair: x, k
queue < pair<int, int> > nodes;
int _x, _k;

void printStatus(){
  system("clear");
  if( !nodes.empty() ) cout << " ";
  printf("     ");
  for(int i = 1; i <= n; i++) cout << i;
  printf("   par  impar\n");

  int current = nodes.front().first;


  for(int i = 1; i <= n; i++){
    if(i == current)
      cout << YEL;
    if(caminos[current][i] == 1)
      cout << GRE;

    if(!nodes.empty())
      cout << (i == current? "\ue602": caminos[current][i] == 1 ? "~":" ");

    printf(" %2d: ", i);
    for(int j = 1; j <= n; j++)
      cout << ( i==j? "\\" : caminos[i][j] ? "*":" ");

    printf("%6d %6d", M[i].first, M[i].second);
    cout << RES << endl;
  }

  queue < pair<int, int> > _nodes = nodes;
  while( !_nodes.empty() ){
    pair <int, int> _front = _nodes.front ();
    if( _front.first == current ) cout << YEL;
    printf("[%2d, %2d] ", _front.first, _front.second);
    cout << RES;
    _nodes.pop();
  }
  cout << endl;

  usleep(delay * 1000000);
}

int main(){

  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int t, t2;
    cin >> t >> t2;
    caminos[t][t2] = 1;
    caminos[t2][t] = 1;
  }

  printStatus();

  nodes.push({1, 1});
  M[1].second = 0;
  while( !nodes.empty() ){
    printStatus();
    pair <int, int> f = nodes.front();
    _x = f.first;
    _k = f.second;

    nodes.pop();
    for(int i = 1; i <= n; i++){
      if(caminos[_x][i] == 1){
        if(M[i].first != 0 && M[i].second != 0)
          continue;
        if( _k%2 == 0 && M[i].first == 0){
          M[i].first = _k;
          nodes.push({ i, _k+1 });
        }
        if( _k%2 != 0 && M[i].second == 0){
          M[i].second = _k;
          nodes.push({ i, _k+1 });
        }
      }
    }
  }
  printStatus();

  cin >> p;
  printf("x: k = result\n");
  for(int i = 0; i < p; i++){
    cin >> _x >> _k;
    printf("%d: %d = ", _x, _k);
    if( _x == 1 && _k == 0 )
      cout << 1;
    else if( _k%2 == 0 && M[_x].first > 0 && M[_x].first <= _k )
      cout << 1;
    else if( _k%2 != 0 && M[_x].second > 0 && M[_x].second <= _k )
      cout << 1;
    else
      cout << 0;
    cout << endl;
  }
}
