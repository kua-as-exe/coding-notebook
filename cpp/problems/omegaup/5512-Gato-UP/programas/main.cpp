#include <bits/stdc++.h>
using namespace std;
int x[10];

bool ifwin(int p){
  if(
    (x[1] == p && x[2] == p && x[3] == p) ||
    (x[4] == p && x[5] == p && x[6] == p) ||
    (x[7] == p && x[8] == p && x[9] == p) ||
    (x[1] == p && x[4] == p && x[7] == p) ||
    (x[2] == p && x[5] == p && x[8] == p) ||
    (x[3] == p && x[6] == p && x[9] == p) ||
    (x[1] == p && x[5] == p && x[9] == p) ||
    (x[7] == p && x[5] == p && x[3] == p)
  ) return 1;
  return 0;
}

int main(){
  for(int i = 1; i <= 9; i++)
    cin >> x[i];
  if( ifwin(1) ){
    printf("Player 1 Wins");
    return 0;
  }else if( ifwin(2) ){
    printf("Player 2 Wins");
    return 0;
  }else{
    printf("Tie");
  }
  return 0;
}