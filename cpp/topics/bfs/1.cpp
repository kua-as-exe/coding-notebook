#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define queueColumns 4

int m[5000][5000], curr, N, M;

struct node {
  int x;
  int y;
  int p;
};

queue < node > q;

// mode: "numerical" | map
string mode = "map";
/* string mode = "numerical"; */

void printC(int t){
  if( mode == "numerical" ){

    if(t == 0){
      cout << " . ";
    }else{  
      if (t < 10) cout << " ";
      cout << t << " ";
    }

  }else if( mode == "map" ){
    if(t == 0){
      cout << ".";
    }else{
      cout << (t == curr ? "#": "-");
    }
    cout << " ";
  }
}

void printQq(queue<node> &qq) {
  if (!qq.empty()) {
    node tt = qq.front();
    printf("[ %2d, %2d ] ", tt.x, tt.y);
    qq.pop();
  }
}

void printX() {
  system("clear");
  cout << endl;
  queue<node> qq = q;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      printC(m[i][j]);
    for(int k = 0; k < queueColumns; k++)
      printQq(qq);
    cout << endl;
  }
  usleep(500000);
}

void add(int x, int y, int p) {
  if (x < 0 || x >= N)
    return;
  if (y < 0 || y >= M)
    return;
  if (m[x][y] > 0)
    return;
  /* if(p > 10) return; */

  m[x][y] = p;
  q.push({x, y, p+1});
}

int main() {
  printX();
  add(5, 5, 1);
  add(N-8, N-3, 1);
  add(N-3, 4, 1);
  add(0, N-6, 1);

  int i = 1;
  while (q.size() != 0) {
    node t = q.front();
    q.pop();

    if( t.p  > curr ){
      printX();
      curr = t.p;
    }

    add(t.x+1, t.y  , t.p);
    add(t.x-1, t.y  , t.p);
    add(t.x,   t.y-1, t.p);
    add(t.x,   t.y+1, t.p);

    /* add(t.x-1, t.y-1, t.p); */
    /* add(t.x+1, t.y+1, t.p); */
    /* add(t.x-1, t.y+1, t.p); */
    /* add(t.x+1, t.y-1, t.p); */
   
    i++;
  }
  
  printX();

  return 0;
}
