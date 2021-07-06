#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string x;
  while (n--){
    cin >> x;
    if(x.size() > 10){
      cout << *x.begin();
      cout << x.size()-2;
      cout << *(x.end()-1);
    } else{
      cout << x;
    }
    cout << endl;
  }
  return 0;
}