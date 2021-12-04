#include <iostream>
#include <stdio.h>
using namespace std;

int m, n, t[1005], y[1005], z[1005];

int Baloons(int T, int i){
  int _t = 0, b = 0;
  while(_t < T){
    _t+= t[i];
    b++;
    if( b%z[i] == 0 ) _t += y[i];
  }
  return b;
}

int Total(int T){
  int sum = 0;
  for(int i = 0; i < n; i++)
    sum += Baloons(T, i);
  return sum;
}

int main(){

  std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false);
  
  cin >> m >> n;
  for(int i = 0; i < n; i++)
    cin >> t[i] >> y[i] >> z[i];
  
  /* for(int T = 0; T < 10; T++){ */
  /*   printf("Time: %d\n", T); */
  /*   for(int i = 0; i < n; i++){ */
  /*     printf("%2d | %2d, %2d, %2d | %2d\n", i, t[i], z[i], y[i], Baloons(T, i)); */
  /*   } */
  /* } */ 

  int i = 0, f = 10e8, mit;
  while(i <= f){
    mit = i +(f-i)/2;
    if( Total(mit) > m ) f = mit-1;
    else i = mit+1;
  }
  int T = i;

  cout << T << endl;
  for(int i = 0; i < n; i++)
    cout << Baloons(T, i) << " ";
  

  return 0;
}
