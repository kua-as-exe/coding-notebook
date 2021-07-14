
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define queueColumns  3
#define delay 0.3 // seconds

#define RES "\u001b[0m"
#define RED "\u001b[31m"
#define GRE "\u001b[32m"
#define YEL "\u001b[33m"
#define BRI_WHI "\u001b[37;1m"

int maxN, maxM;
int m[5000][5000], E[5000][5000], o[5000][5000];
int curr, N=0, M=0, n, Q, _x, _y;

struct node {
  int x;
  int y;
  int p;
  int e;
};

queue<node> q;

void printC(int t) {
  if(t == 0){
    cout << ".";
  }else{
    char c = t+'a'-1;
    cout << c;
  }
  cout << " ";
}

void printQq(queue<node> &qq) {
  node tt = qq.front();
  printf(" [ %2d, %2d, %01d]", tt.x, tt.y, tt.e);
  qq.pop();
}

void printX() {
  int i, j, k;
  /* system("clear"); */
  cout << endl;
  queue<node> qq = q;
  for (i = 0; i < maxM; i++) {
    for (j = 0; j < maxN; j++){
      if(o[i][j] == 1){
        char c = E[i][j]+'A'-1;
        cout << c << " ";
      }else 
        printC(E[i][j]);
    }

    if (queueColumns > 0)
      cout << "|";
    for (k = 0; k < queueColumns && !qq.empty(); k++)
      printQq(qq);

    cout << endl;
  }
  usleep(delay * 1000000);
}

void add(int x, int y, int p, int e) {
  if ( x < 0 || x >= maxM || y < 0 || y >= maxN ) return;
  if ( m[x][y] > 0 && m[x][y] < p+1 ) return;
  if ( m[x][y] == -1 ) return;

  E[x][y] = e;
  m[x][y] = p;
  /* printX(); */
  q.push({x, y, p + 1, e});
}

int main() {
  cin >> n >> Q;
  /* char tchar; */
  /* cout << "PROGRAM " << n; */
  for(int a = 1; a <= n; a++){
    cin >> _x >> _y;
    maxN = max(_y, maxN);
    maxM = max(_x, maxM);
    o[_x-1][_y-1] = 1;
    add(_x-1, _y-1, 1, a);
  }
  /* maxM++; */
  /* maxN++; */
  /* printf("%d & %d\n", maxM, maxN); */
  /* for (int a = 0; a < N; a++) { */
  /*   for (int b = 0; b < M; b++) { */
  /*     cin >> tchar; */
  /*     if (tchar == 'o') { */
  /*       add(a, b, 1); */
  /*     } else if (tchar == '#') { */
  /*       m[a][b] = -1; */
  /*     } */
  /*   } */
  /* } */

  /* printX(); */

  while (!q.empty()) {
    node t = q.front();
    q.pop();

    if (t.p > curr) {
      /* printX(); */
      curr = t.p;
    }

    add(t.x + 1, t.y, t.p, t.e);
    add(t.x - 1, t.y, t.p, t.e);
    add(t.x, t.y - 1, t.p, t.e);
    add(t.x, t.y + 1, t.p, t.e);
    add(t.x - 1, t.y - 1, t.p, t.e);
    add(t.x + 1, t.y + 1, t.p, t.e);
    add(t.x - 1, t.y + 1, t.p, t.e);
    add(t.x + 1, t.y - 1, t.p, t.e);
  }

  printX();

  for( int b = 0;  b < Q; b++ ){
    cin >> _x >> _y;
    /* _x --; */
    /* _y --; */
  /* for (int i = 0; i < maxM; i++) { */
  /*   for (int j = 0; j < maxN; j++){ */
  /*     if( m[i][j] == 1 ) */
  /*       cout << "#" << " "; */
  /*     else if( _x == i && _y == j ) */
  /*       cout  << "@" << " "; */
  /*     else */ 
  /*       cout << m[i][j] << " "; */
  /*   } */

  /*   cout << endl; */
  /* } */
    cout << m[_x-1][_y-1]-1 << "\n";
  }

  return 0;
}
