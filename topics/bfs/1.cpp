#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define queueColumns  5
#define delay 0.1 // seconds

#define RES "\u001b[0m"
#define RED "\u001b[31m"
#define GRE "\u001b[32m"
#define YEL "\u001b[33m"
#define BRI_WHI "\u001b[37;1m"

int m[5000][5000], curr, N, M;

struct node {
  int x;
  int y;
  int p;
};

queue<node> q;

void printC(int t) {
  if (t == 0) {
    cout << " ";
  } else if (t == -1) {
    cout << BRI_WHI << "#" << RES;
  } else {
    if (t == curr) {
      cout << YEL << "@" << RES;
    } else {
      string c = ".";
      /* int c = (t-1)%9+1; */
      /* char c = (t-1)%26 + 'a'; */
      cout << GRE << c << RES;
    }
  }
  cout << " ";
}

void printQq(queue<node> &qq) {
  node tt = qq.front();
  printf(" [ %2d, %2d ]", tt.x, tt.y);
  qq.pop();
}

void printX() {
  int i, j, k;
  system("clear");
  cout << endl;
  queue<node> qq = q;
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++)
      printC(m[i][j]);

    if (queueColumns > 0)
      cout << "|";
    for (k = 0; k < queueColumns && !qq.empty(); k++)
      printQq(qq);

    cout << endl;
  }
  usleep(delay * 1000000);
}

void add(int x, int y, int p) {
  if (x < 0 || x >= N || y < 0 || y >= M)
    return;
  if (m[x][y] > 0 || m[x][y] == -1)
    return;

  m[x][y] = p;
  q.push({x, y, p + 1});
}

int main() {

  cin >> N >> M;

  char tchar;
  for (int a = 0; a < N; a++) {
    for (int b = 0; b < M; b++) {
      cin >> tchar;
      if (tchar == 'o') {
        add(a, b, 1);
      } else if (tchar == '#') {
        m[a][b] = -1;
      }
    }
  }

  printX();

  while (!q.empty()) {
    node t = q.front();
    q.pop();

    if (t.p > curr) {
      printX();
      curr = t.p;
    }

    add(t.x + 1, t.y, t.p);
    add(t.x - 1, t.y, t.p);
    add(t.x, t.y - 1, t.p);
    add(t.x, t.y + 1, t.p);

    /* // Square */
    /* if (m[t.x - 1][t.y] != -1 && m[t.x][t.y - 1] != -1) */
    /*   add(t.x - 1, t.y - 1, t.p); */
    /* if (m[t.x + 1][t.y] != -1 && m[t.x][t.y + 1] != -1) */
    /*   add(t.x + 1, t.y + 1, t.p); */
    /* if (m[t.x - 1][t.y] != -1 && m[t.x][t.y + 1] != -1) */
    /*   add(t.x - 1, t.y + 1, t.p); */
    /* if (m[t.x + 1][t.y] != -1 && m[t.x][t.y - 1] != -1) */
    /*   add(t.x + 1, t.y - 1, t.p); */
  }

  printX();

  return 0;
}
