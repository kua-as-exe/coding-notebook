#include <iostream>
#include <string>
using namespace std;

int n, o = 0;
string x;

int main(){
  cin >> n >> x;
  cout << x << " - " << n << endl;
  while(x.size() > 1){
    o++;
    if( x == "11" ) {
       o++; break; 
    } else if ( x.back() == '0' ){ 
      // división
      cout << "(D) ";
      x.pop_back();
    } else{
      int l=x.size()-1;
      if( x[l-1] == '0' ){ 
        // resta
        cout << "(R) ";
        x.back() = '1';
      } else { 
        // suma
        cout << "(S) ";
        int i = l;
        while(i >= 0 && x[i] == '1'){
          x[i] = '0'; i--;
        }
        if(i > 0)
          x[i] = '1';
        else
          x.insert(x.begin(), '1');
        
      }
    }
    cout << x << " - " << n << endl;
  }
  cout << o ;
  return 0;
}