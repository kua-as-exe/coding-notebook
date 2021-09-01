#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n, m, Min = 0;

bool _debug = false;
#define DEBUG if(_debug) 

vector<int> places;
vector<int> solution;
vector<int> v, s;

int getDif(int pos){
  /* DEBUG printf(" POS OF %d\n", pos); */ 
  if( pos == 0 ) 
    return abs( v[pos] - v[pos+1] );

  else if( pos == n-1 ) 
    return abs( v[pos] - v[pos-1] );

  else 
    return ( abs( v[pos] - v[pos+1] ) + abs( v[pos] - v[pos-1] ) )/2;

}

vector<bool> used;

void backtracking( int pos, int diff){
  /* DEBUG printf("%d - %d\n", pos, diff); */
  if( Min > 0 && diff >= Min ) return;
  if( pos == places.size() ) {
    DEBUG printf("Option founded:\n ");

    DEBUG {
      for( int i = 0; i < n; i++  )
        cout << v[i] << " ";
      printf(" (%d)\n", diff);
    }

    if( Min == 0 || diff < Min ){
      Min = diff;
      solution = v;
    }

    return;
  };

  for( int i = 0; i < used.size(); i++){
    if( !used[i] ){
      used[i] = true;
      v[ places[pos] ] = s[i];
      
      /* DEBUG printf("Joining to: %d (%d) with %d\n", places[pos], v[places[pos]], getDif( places [pos] )); */
      backtracking(pos+1, diff + getDif( places [pos] ) );

      used[i] = false;
      v[ places[pos] ] = 0;
    }
  }
}

int main(){

  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  cin >> n >> m;
  
  v.resize(n);
  solution.resize(n);
  s.resize(m);

  for(int i = 0; i < n; i++) {
    cin >> v[i];
    if( v[i] == 0 )
      places.push_back(i);
  }
  for(int i = 0; i < m; i++) cin >> s[i];

  used.resize(m);
  backtracking(0, 0);

  int diff = 0;
  for(int i = 0; i < n-1; i++)
    diff += abs(solution[i]-solution[i+1]);

  cout << diff << endl;
  for(int i = 0; i < n; i++)
    cout << solution[i] << " ";

  return 0;
}
