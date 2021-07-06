#include <iostream>
using namespace std;
int main(){
  int L1, T1, L2, T2;
  cin >> L1 >> T1;
  cin >> L2 >> T2;
  if(L1 > L2 && T1 > T2) 
    cout << "Hueso 1";
  else if(L2 > L1 && T2 > T1) 
    cout << "Hueso 2";
  else 
    cout << "Perrito confundido :(";
  return 0;
}