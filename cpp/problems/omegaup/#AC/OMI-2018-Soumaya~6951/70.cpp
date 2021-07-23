#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <iterator>
#include <vector>
using namespace std;

#define delay 0.3 // seconds
bool animated = false;

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

struct pos{
  int x, y;
};

pos current_cell = {-1, -1};

vector<zone> zones;
vector<string> zonesColors = { YEL, GRE, CYA, MAG, BLU, RED };

char getChar(int v){
  v = v%26;
  if( v == 0 ) v = 26;
  char c = v+'a'-1;
  return c;
}
void printMap(){
  printf("   ");
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
          cout << zonesColors[zz%zonesColors.size()];

      if( mapa[i][j] == -1 )
        cout << ".";
      else
        cout << getChar(mapa[i][j]); 
      cout << RES;
    }

    printf(" | ");

    for(int j = 0; j < m; j++){
      if( i == current_cell.x && j == current_cell.y )
        cout << RED;
      if( mapa2[i][j] == 0 )
        cout << ".";
      else 
        cout << getChar(mapa2[i][j]); 
      cout << RES;
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


void mergeZones(zone *zone1, zone *zone2){
  /* printf(" ~ Merge %d & %d\n", zone1->index, zone2->index); */

  zone1->t = min(zone1->t, zone2->t);
  zone1->b = max(zone1->b, zone2->b);
  zone1->l = min(zone1->l, zone2->l);
  zone1->r = max(zone1->r, zone2->r);

  /* vector<zone>::iterator a = zones.begin()+zone2->index; */
  /* zones.erase(a); */
  /* for(int i = 0; i < zones.size(); i++) */
  /*   zones[i].index = i; */

}

bool checkValid(int i, int j, int ii, int jj){
  /* printf("Checking in (%d, %d: %d) & (%d, %d: %d)\n", i, j, mapa2[i][j], ii, jj, mapa2[ii][jj]); */
  if( mapa2[ii][jj] > 0 && mapa2[ii][jj] < mapa2[i][j] ){
    /* printf("Invalid position in (%d, %d: %d) & (%d, %d: %d)\n", i, j, mapa2[i][j], ii, jj, mapa2[ii][jj]); */
    current_cell = {i, j};
    mergeZones( &zones[ mapa2[i][j]-1 ] , &zones[ mapa2[ii][jj]-1 ]);
    return false;
  }
  return true;
}

int main(){
  if(!animated){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
  }

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

  int index = 0;
  while( index < zones.size() ){
    zone *z = &zones[index];
    if(animated){
      system("clear");
      printf("\n%d (%d): \n", index, z->index+1);
      printMap(); 
    }

    bool merged = false;
    for(int i = z->t; i <= z->b && !merged; i++){
      for(int j = z->l; j <= z->r && !merged; j++){
        mapa2[i][j] = z->index+1;
        if( index > 0 ){
          /* printf("[%d, %d]\n", i, j); */
          if( i > 0 && !checkValid(i, j, i-1, j) ) merged = true ;
          if( !merged && i < n-1 && !checkValid(i, j, i, j-1) ) merged = true ;
          if( !merged && j > 0 && !checkValid(i, j, i+1, j) ) merged = true ;
          if( !merged && j < m-1 && !checkValid(i, j, i, j+1) ) merged = true ;
        }
      }
    }
    if(merged){
      /* printf("Filling (%d, %d; %d, %d) with %d\n", z->t, z->l, z->b, z->r, z->index+1); */
      for(int i = z->t; i <= z->b ; i++){
        for(int j = z->l; j <= z->r ; j++){
          mapa2[i][j] = z->index+1;
        }
      }
      index --;
    }
    /* printZones(); */

    index++;
    if(animated) usleep(delay * 1000000);
  }
  current_cell = {-1, -1};
  if(animated){

    printf("\n");
    printMap(); 
  }

  if( !animated ){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cout << ( mapa2[i][j] == 0 ? '0':'1' );
      }
      cout << "\n";
    }
  }

  return 0;
}
