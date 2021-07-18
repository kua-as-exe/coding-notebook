#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int n, p=0; string x; 
  cin >> n >> x;
  reverse(x.begin(), x.end());

  while(x!="1"){
    if(x == "11") { p+=2; break; }
    if(x[0] == '0') x.erase(x.begin());
    
    else {
      if(x[1]=='0') x[0] = '0';
      
      else{
        int l = x.length();
        for(int i = 0; i < l; i++){
          if(x[i] == '0'){
            x[i] = '1'; break;
          } else {
            x[i] = '0';
            if(x[i+1] == '0' && i < l-1){
              x[i+1] = '1'; break;
            }
            else if(i == l-1)
              x.push_back('1');    
          }
        }
      }
    } 
    p++;
  }
  //cout << x << endl;
  cout << p;
  return 0;
}