// AC
#include <iostream>
#include <queue>
using namespace std;

int m[1010][1010];
int n, Q, _x, _y;

struct node {
  int x;
  int y;
  int p;
};

queue<node> q;

void add(int x, int y, int p) {
  if ( x < 0 || x > 1000 || y < 0 || y > 1000 ) return;
  if ( m[x][y] > 0 ) return;
  if ( m[x][y] == -1 ) return;
  m[x][y] = p;
  q.push({x, y, p + 1 });
}

int main() {
  cin >> n >> Q;
  for(int a = 0; a < n; a++){
    cin >> _x >> _y;
    add(_x, _y, 1);
  }

  while (!q.empty()) {
    node t = q.front();
    q.pop();

    add(t.x + 1, t.y, t.p);
    add(t.x - 1, t.y, t.p);
    add(t.x, t.y - 1, t.p);
    add(t.x, t.y + 1, t.p);
    add(t.x - 1, t.y - 1, t.p);
    add(t.x + 1, t.y + 1, t.p);
    add(t.x - 1, t.y + 1, t.p);
    add(t.x + 1, t.y - 1, t.p);
  }
  for( int b = 0;  b < Q; b++ ){
    cin >> _x >> _y;
    cout << m[_x][_y]-1 << "\n";
  }

  return 0;
}
