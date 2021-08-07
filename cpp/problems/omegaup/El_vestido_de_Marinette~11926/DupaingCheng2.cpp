#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

bool debug = false;
#define DEBUG if( debug )

char mapa[2005][2005], color;
short int pisado[2005][2005];
short int n, m, count = 0, current = 0, corte = 1;
bool valid;

struct node{
  short int x, y, p;
};

queue < node > nodes;

void printM(){

  for( int i = 0; i < n; i++ ){

    for(int j = 0; j < m; j++)
      printf("%c ", mapa[i][j]);

    cout << " ";

    for(int j = 0; j < m; j++)
      printf("%2d ", pisado[i][j]);
    
    cout << endl;
  }
}

void printQ(){
  queue<node> qt = nodes;
  while(!qt.empty()){
    node f = qt.front();
    printf("[%2d,%2d |%2d] ", f.x, f.y, f.p);
    qt.pop();
  }
}

void add(short int x, short int y, short int p){
  if( x < 0 || x >= n || y < 0 || y >= m || mapa[x][y] != color){
    valid = false;
    return;
  }
  if( !valid || pisado[x][y] == corte ) return;

  pisado[x][y] = corte;
  nodes.push({ x, y, p });

  return;
}

void bfs(int x, int y){
  DEBUG printf("\nBFS in: %d %d\n", x, y);
  current = 1;
  valid = true;
  color = mapa[x][y];
  
  DEBUG {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        pisado[i][j] = 0;
  }
  add(x, y, 1);

  while ( !nodes.empty() && valid ) {
    node f = nodes.front();
    DEBUG printf("Front: %d, %d p:%d\n", f.x, f.y, f.p );
    nodes.pop();

    if( f.p == 1 || f.p > current ){
      count++;
      DEBUG printM();
      current = f.p;
    }

    add(f.x+1, f.y, f.p+1);
    add(f.x-1, f.y, f.p+1);
    add(f.x, f.y+1, f.p+1);
    add(f.x, f.y-1, f.p+1);

  }

  while ( !nodes.empty() ) nodes.pop();

  corte++; 
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> mapa[i][j];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      bfs(i, j);

  cout << count;
}

