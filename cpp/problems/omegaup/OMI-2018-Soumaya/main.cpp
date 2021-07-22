#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define BLA "\u001b[30m"
#define RED "\u001b[31m"
#define GRE "\u001b[32m"
#define YEL "\u001b[33m"
#define BLU "\u001b[34m"
#define MAG "\u001b[35m"
#define CYA "\u001b[36m"
#define WHI "\u001b[37m"
#define BRI_BLA "\u001b[30;1m"
#define BRI_RED "\u001b[31;1m"
#define BRI_GRE "\u001b[32;1m"
#define BRI_YEL "\u001b[33;1m"
#define BRI_BLU "\u001b[34;1m"
#define BRI_MAG "\u001b[35;1m"
#define BRI_CYA "\u001b[36;1m"
#define BRI_WHI "\u001b[37;1m"
#define BG_BLA "\u001b[40m"
#define BG_RED "\u001b[41m"
#define BG_GRE "\u001b[42m"
#define BG_YEL "\u001b[43m"
#define BG_BLU "\u001b[44m"
#define BG_MAG "\u001b[45m"
#define BG_CYA "\u001b[46m"
#define BG_WHI "\u001b[47m"
#define BG_BRI_BLA "\u001b[40;1m"
#define BG_BRI_RED "\u001b[41;1m"
#define BG_BRI_GRE "\u001b[42;1m"
#define BG_BRI_YEL "\u001b[43;1m"
#define BG_BRI_BLU "\u001b[44;1m"
#define BG_BRI_MAG "\u001b[45;1m"
#define BG_BRI_CYA "\u001b[46;1m"
#define BG_BRI_WHI "\u001b[47;1m"
#define RES "\u001b[0m"
#define BOL "\u001b[1m"
#define UND "\u001b[4m"
#define REV "\u001b[7m"

int n, m, t;
int mapa[1501][1501];
int mapa2[1501][1501];

struct zone{
  int l, r, t, b;
  int index;
};

vector<zone> zones;
string zonesColors[] = { YEL, GRE, CYA, MAG, BLU, RED };

void printMap(){
  printf("\n   ");
  for(int i = 0; i < m; i++) cout << i%10;
  printf("   ");
  for(int i = 0; i < m; i++) cout << i%10;
  cout << endl;

  for(int i = 0; i < n; i++){
    printf("%2d ", i);
    for(int j = 0; j < m; j++){

      for(int zz = 0; zz < zones.size(); zz++)
        if( i >= zones[zz].t && i <= zones[zz].b &&
            j >= zones[zz].l && j <= zones[zz].r)
          cout << zonesColors[zz];

      if( mapa[i][j] == -1 )
        cout << ".";
      else
        cout << mapa[i][j];
      cout << RES;
    }

    printf(" | ");

    for(int j = 0; j < m; j++){
      cout << mapa2[i][j];
    }
    cout << endl;
  } 
}
void printZones(){
  for(int i = 0; i < zones.size(); i++){
    zone z = zones[i];
    printf("%d: { t: %d, b: %d, l: %d, r: %d }\n", z.index+1, z.t, z.b, z.l, z.r);
  }
}

void dfs(int i, int j, int zoneIndex ){
  if (i < 0 || j < 0 || i >= n || j >= m ) return;
  if ( mapa[i][j] == -1 || mapa[i][j] > 0 ) return;

  mapa[i][j] = zoneIndex+1;
  
  zone *current = &zones[zoneIndex];
  if( i < current->t ) current->t = i;
  if( i > current->b ) current->b = i;
  if( j < current->l ) current->l = j;
  if( j > current->r ) current->r = j;
  /* printMap(); */
  /* printZones(); */

  dfs(i+1, j  , zoneIndex);
  dfs(i-1, j  , zoneIndex);
  dfs(i  , j+1, zoneIndex);
  dfs(i  , j-1, zoneIndex);

}

bool checkValid(int i, int j){
  bool _debug = false;
  if( i > 0 && mapa[i-1][j] != mapa[i][j] )
    if( mapa2[i-1][j] != 0 && mapa2[i-1][j] != mapa2[i][j] ){
      if(_debug) printf("(%d, %d) & (%d, %d)\n", i, j, i-1, j);
      return false;
    }
  if( j > 0 && mapa[i][j-1] != mapa[i][j] )
    if( mapa2[i][j-1] != 0 && mapa2[i][j-1] != mapa2[i][j] ){
      if(_debug) printf("(%d, %d) & (%d, %d)\n", i, j, i, j-1);
      return false;
    }
  if( i < n-1 && mapa[i+1][j] != mapa[i][j] )
    if( mapa2[i+1][j] != 0 && mapa2[i+1][j] != mapa2[i][j] ){
      if(_debug) if(_debug) printf("(%d, %d) & (%d, %d)\n", i, j, i+1, j);
      return false;
    }
      if( j < m-1 && mapa[i][j+1] != mapa[i][j] )
    if( mapa2[i][j+1] != 0 && mapa2[i][j+1] != mapa2[i][j] ){
      if(_debug) printf("(%d, %d) & (%d, %d)\n", i, j, i, j+1);
      return false;
    }
  return true;
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      char c;
      cin >> c;
      mapa[i][j] = (c == '0' ? -1 : 0);
    }
  }
  printMap();

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if( mapa[i][j] == 0 ){
        /* printf("Zoned pushed back in: %d\n", (int)zones.size() ); */
        zones.push_back({ j, j, i, i, (int)zones.size() });
        dfs(i, j, zones.back().index );
      }
    }
  } 

  int index = 0;
  while( index < zones.size() ){
    printMap(); 
    printZones();

    zone z = zones[index];
    for(int i = z.t; i <= z.b; i++){
      for(int j = z.l; j <= z.r; j++){
        mapa2[i][j] = z.index+1;
        if( index > 0 && !checkValid(i, j) )
          printf("Not valid position in [%d, %d]\n", i, j);
      }
    }
    /* zone b = zones[index+1]; */
    
    index++;
  }

  printMap(); 
  printZones();

  return 0;
}
