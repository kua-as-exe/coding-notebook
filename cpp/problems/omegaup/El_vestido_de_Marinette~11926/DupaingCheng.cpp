#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

bool debug = true;
#define DEBUG if( debug )

int mapa[2005][2005];
int pisado[2005][2005];

int n, m; 
int count = 0;
int current = 0;
int corte = 1;
int in_lvl = 0;
bool salir = false;

struct node{
  int x, y, p, c;
};

queue < node > nodes;

void printM(){

  for( int i = 0; i < n; i++ ){

    for(int j = 0; j < m; j++){
      printf("%c ", mapa[i][j]+'a'-1);
    }
    cout << " ";
    for(int j = 0; j < m; j++){
      printf("%2d ", pisado[i][j]);
    }

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

void add(int x, int y, int p, int c){
  DEBUG printf("In: %d, %d\n", x, y);
  if( x < 0 || x >= n || y < 0 || y >= m)
    salir = true;
  if( mapa[x][y] != c )
    salir = true;
  if (salir)
    return;
  if( pisado[x][y] == corte ) return;

  p++;
  DEBUG printf("Added node in: (%d, %d) color: %c, p: %d\n", x, y, c+'a'-1, p);

  in_lvl++;
  pisado[x][y] = corte;

  nodes.push({x, y, p, c});

}

void bfs(int x, int y){
  printf("\nBFS in: %d %d\n", x, y);
  salir = false;
  count ++;
  in_lvl = 0;
  current = 1;

  DEBUG {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        pisado[i][j] = 0;
  }

  add(x, y, 0, mapa[x][y]);

  while (!nodes.empty() && !salir) {
    node f = nodes.front();
    DEBUG printf("Front: %d, %d p:%d  color: %d\n", f.x, f.y, f.p, f.c);
    nodes.pop();

    DEBUG printM();
    DEBUG printQ();
    if( f.p > current ){
      DEBUG printf("From %d -> %d\n", current, f.p);
      current = f.p;
      DEBUG printf("Lvl: %d\n", in_lvl);
      int expected_lvl = f.p > 1 ? 4*(f.p-1) : 1;
      if( in_lvl == expected_lvl){
        count++;
      } else {
        DEBUG printf("Lvl not enough (%d/%d)\n", in_lvl, expected_lvl );
        salir = true;
        return;
      }
      /* in_lvl = 0; */
    }
    

    add(f.x+1, f.y, f.p, f.c);
    add(f.x-1, f.y, f.p, f.c);
    add(f.x, f.y+1, f.p, f.c);
    add(f.x, f.y-1, f.p, f.c);

  }

  corte++; 
}

int main(){
  cin >> n >> m;

  char c;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> c;
      mapa[i][j] = c-'a'+1;
    }
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      bfs(i, j);

  cout << count;
}

