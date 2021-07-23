#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <iterator>
#include <vector>
using namespace std;

#define delay 0.3 // seconds
bool animated = true;

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
int mapa2[1505][1501];

struct zone{
  int l, r, t, b;
  int index;
};

struct pos{
  int x, y;
};

pos current_cell = {-1, -1};

vector<zone> zones;
vector<string> zonesColors = { 
  BRI_YEL, 
  BRI_GRE, 
  BRI_CYA, 
  BRI_MAG, 
  BRI_BLU, 
  /* RED, */
};

char getC(int v){
  v = v%26;
  if( v == 0 ) v = 26;
  char c = v+'a'-1;
  return c;
}
void printMap(){
  printf("   ");
  for(int i = 0; i < m; i++) cout << i%10;
  cout << endl;

  for(int i = 0; i < n; i++){
    printf("%2d ", i);
    for(int j = 0; j < m; j++){

      bool isLimit = false;
      int color = -1;
      for(int zz = 0; zz < zones.size(); zz++){
        zone z = zones[zz];
        isLimit = isLimit || ( 
            ( i == z.t-1 && j >= z.l-1 && j <= z.r+1 ) ||
            ( i == z.b+1 && j >= z.l-1 && j <= z.r+1 ) ||
            ( j == z.l-1 && i >= z.t-1 && i <= z.b+1 ) ||
            ( j == z.r+1 && i >= z.t-1 && i <= z.b+1 )
            );

        if( i >= z.t && i <= z.b && j >= z.l && j <= z.r )
          color = zz;
      }

      if( isLimit ) cout << RED;
      if(color != -1 ) cout << zonesColors[color%zonesColors.size()];

      if( mapa[i][j] == -1 )
        cout << ".";
      else
        cout  << getC(mapa[i][j]); 
      cout << RES;
    }

    cout << endl;
  } 
}
void printZones(){
  for(int i = 0; i < zones.size(); i++){
    zone z = zones[i];
    printf("%c: { t: %d, b: %d, l: %d, r: %d }\n", getC(z.index+1), z.t, z.b, z.l, z.r);
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

void mergeZones(zone *zone1, zone *zone2){
  if(animated) printf(" ~ Merge %c & %c\n", getC(zone1->index+1), getC(zone2->index+1));

  zone1->t = min(zone1->t, zone2->t);
  zone1->b = max(zone1->b, zone2->b);
  zone1->l = min(zone1->l, zone2->l);
  zone1->r = max(zone1->r, zone2->r);

  vector<zone>::iterator a = zones.begin()+zone2->index;
  zones.erase(a);
  for(int zz = 0; zz < zones.size(); zz++){
    zones[zz].index = zz;
    zone z = zones[zz];
    for( int i = 0; i < n; i++ ){
      for( int j = 0; j < m; j++ ){
        if( i >= z.t && i <= z.b && j >= z.l && j <= z.r ){
          mapa[i][j] = z.index+1;
        }
      }
    }
  }

}

bool checkValid(int i, int j, int index){
  printf("Checking (%d, %d\n", i, j );

  for( int zi = 0; zi < zones.size(); zi++){
    if( zi == index ) continue; // ignore if its itself
    zone *z = &zones[zi];

    if( 
        ( i == z->t-1 && j >= z->l && j <= z->r ) ||
        ( i == z->b+1 && j >= z->l && j <= z->r ) ||
        ( j == z->l-1 && i >= z->t && i <= z->b ) ||
        ( j == z->r+1 && i >= z->t && i <= z->b ) ||
        ( i >= z->t && i <= z->b && j >= z->l && j <= z->r )
      ){
      /* printf("Invalid position in (%d, %d) %c vs %c\n", i, j, getC(index+1), getC(z->index+1)); */
      current_cell = {i, j};
      mergeZones( &zones[index] , z );
      return false;
    }
  }

  return true;
}

int main(){
  if(!animated){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); }

  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      char c;
      cin >> c;
      mapa[i][j] = (c == '0' ? -1 : 0);
    }
  }
  /* printMap(); */

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if( mapa[i][j] == 0 ){
        /* printf("Zoned pushed back in: %d\n", (int)zones.size() ); */
        zones.push_back({ j, j, i, i, (int)zones.size() });
        dfs(i, j, zones.back().index );
      }
    }
  } 

  bool done = false;
  /* while( !done ){ */
    int index = 0;
    bool cases = false;
    while ( index < zones.size() ){
      zone *z = &zones[index];
      if(animated){
       /* system("clear"); */
        printf("\n%d (%d): \n", index, z->index+1);
        printMap(); 
      }

      bool merged = false;
      if( !checkValid(z->t, z->l, z->index) ) merged = true; // top left
      if( !merged && !checkValid(z->t, z->r, z->index) ) merged = true; // top right
      if( !merged && !checkValid(z->b, z->l, z->index) ) merged = true; // bottom left
      if( !merged && !checkValid(z->b, z->r, z->index) ) merged = true; // bottom right
      
      printZones();

      if( merged ){
        cases = true;
        index = z->index;
      } else {
        index++;
      }
      if(animated) usleep(delay * 1000000);
    }
    if(!cases) done = true;
  /* } */

  current_cell = {-1, -1};
  if(animated){
    printf("\n");
    printMap(); 
  }
  
  if( !animated ){
    for( int zz = 0; zz < zones.size(); zz++ ){
      zone z = zones[zz];
      for(int i = z.t; i <= z.b; i++){
        for(int j = z.l; j <= z.r; j++){
          mapa2[i][j] = 1;
        }
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cout << mapa2[i][j];
      }
      cout << "\n";
    }
  }

  return 0;
}
