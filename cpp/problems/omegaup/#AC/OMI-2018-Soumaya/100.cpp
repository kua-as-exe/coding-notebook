#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <vector>
using namespace std;

bool animated = false;
#define delay 0.3 // seconds

#define debug if(animated)
#define notdebug if(!animated)

#define RED "\u001b[31m"
#define GRE "\u001b[32m"
#define YEL "\u001b[33m"
#define BLU "\u001b[34m"
#define MAG "\u001b[35m"
#define CYA "\u001b[36m"
#define RES "\u001b[0m"

int n, m;
int mapa[1501][1501];
int mapa2[1501][1501];

struct zone{
  int l, r, t, b;
  int index;
  bool death = false;
};

struct pos{
  int x, y;
};

vector<zone> zones;

// debug animation
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

// actual code

void dfs(int i, int j, int zoneIndex ){
  if (i < 0 || j < 0 || i >= n || j >= m ) return;
  if ( mapa[i][j] == -1 || mapa[i][j] > 0 ) return;

  mapa[i][j] = zoneIndex+1;

  zone *current = &zones[zoneIndex];
  if( i < current->t ) current->t = i;
  if( i > current->b ) current->b = i;
  if( j < current->l ) current->l = j;
  if( j > current->r ) current->r = j;

  dfs(i+1, j  , zoneIndex);
  dfs(i-1, j  , zoneIndex);
  dfs(i  , j+1, zoneIndex);
  dfs(i  , j-1, zoneIndex);
}

void mergeZones(zone *zone1, zone *zone2){
  debug printf(" ~ Merge %d & %d\n", zone1->index, zone2->index);

  zone1->t = min(zone1->t, zone2->t);
  zone1->b = max(zone1->b, zone2->b);
  zone1->l = min(zone1->l, zone2->l);
  zone1->r = max(zone1->r, zone2->r);

  zone2->death = true;
}

bool checkInvalid(int i, int j, int ii, int jj){
  /* printf("Checking in (%d, %d: %d) & (%d, %d: %d)\n", i, j, mapa2[i][j], ii, jj, mapa2[ii][jj]); */
  if( mapa2[ii][jj] > 0 && mapa2[ii][jj] < mapa2[i][j] ){
    debug printf("Invalid position in (%d, %d: %d) & (%d, %d: %d)\n", i, j, mapa2[i][j], ii, jj, mapa2[ii][jj]);
    mergeZones( &zones[ mapa2[i][j]-1 ] , &zones[ mapa2[ii][jj]-1 ]);
    return true;
  }
  return false;
}

bool check( int i, int j, int index, zone *&z){
  mapa2[i][j] = z->index+1;
  if( index > 0 ){
    if( i > 0 && checkInvalid(i, j, i-1, j) ) return true ;
    if( i < n && checkInvalid(i, j, i, j-1) ) return true ;
    if( j > 0 && checkInvalid(i, j, i+1, j) ) return true ;
    if( j < m && checkInvalid(i, j, i, j+1) ) return true ;
  }
  return false;
}

int main(){
  notdebug {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
  }

  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      char c; cin >> c;
      mapa[i][j] = (c == '0' ? -1 : 0);
    }
  }
  /* printMap(); */

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if( mapa[i][j] == 0 ){
        /* printf("Zoned pushed back in: %d\n", (int)zones.size() ); */
        zones.push_back({ j, j, i, i, (int)zones.size(), false });
        dfs(i, j, zones.back().index );
      }
    }
  } 

  int index = 0;
  while( index < zones.size() ){
    zone *z = &zones[index];

    debug {
      system("clear");
      printf("\n%d (%d): \n", index, z->index+1);
      printMap(); 
    }

    bool merged = false;

    // check
    for(int i = z->t; i <= z->b && !merged; i++) 
      merged = check( i, z->l, index, z); // left side

    for(int i = z->t; i <= z->b && !merged; i++) 
      merged = check( i, z->r, index, z); // right side

    for(int j = z->l; j <= z->r && !merged; j++) 
      merged = check( z->t, j, index, z); // top side

    for(int j = z->l; j <= z->r && !merged; j++) 
      merged = check( z->b, j, index, z); // bottom side

    if( merged ){
      debug printf("filling (%d, %d; %d, %d) with %d\n", z->t, z->l, z->b, z->r, z->index+1);
      // fill expanded content
      for(int i = z->t; i <= z->b ; i++)
        for(int j = z->l; j <= z->r ; j++)
          mapa2[i][j] = z->index+1;

    }else{
      index++;
    }
    /* printZones(); */

    debug usleep(delay * 1000000);
  }

  debug {
    printf("\n");
    printMap(); 
  }

  // Omegaup output
  notdebug {

    for( auto z : zones )
      if( !z.death )
        for(int i = z.t; i <= z.b; i++)
          for(int j = z.l; j <= z.r; j++)
            mapa2[i][j] = 1;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++)
        cout << mapa2[i][j];
      cout << "\n";
    }

  }

  return 0;
}
