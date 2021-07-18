#include <iostream>
#include <string>
using namespace std;

int n, o;
string x;

int main(){
  cin >> n >> x;
  n--;
  //cout << x << " - " << n << endl;
  while(n > 0){
    o++;
    if( n == 1 && x[0] == '1' && x[1] == '1' ) {
       o++; break; 
    } else if ( x[n] == '0' ){ // división
      //cout << "(D) ";
      n--;
    } else{

      if( x[n-1] == '0' ){ // resta
        //cout << "(R) ";
        x[n] = '0';
      } else{ // suma
        //cout << "(S) ";
        int i = n;
        while(i >= 0 && x[i] == '1'){
          x[i] = '0';
          i--;
        }
        if(i > 0)
          x[i] = '1';
        else{
          for(int j = n; j >= 0; j--)
            x[j+1] = x[j];
          x[0] = '1';
          n++;
        }
        
      }

    }
    //cout << x.substr(0, n+1) << " - " << n << endl;
  }
  cout << o ;
  return 0;
}