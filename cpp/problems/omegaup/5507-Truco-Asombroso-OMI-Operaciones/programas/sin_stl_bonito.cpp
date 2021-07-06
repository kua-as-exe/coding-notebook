#include <iostream>
#include <string>
using namespace std;

int n, o;
string x;

void division(){
  n--;
  o++;
}

void resta(){ 
  x[n] = '0';
  o++;
}

void suma(){ 
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
  o++;
}

int esTres(){
  if(n == 1 && x[0] == '1' && x[1] == '1'){
    o+=2; 
    return 1;
  }
  return 0;
}

int main(){
  cin >> n >> x;
  n--;
  while(n > 0){
    if( esTres() ) 
      break;
    if ( x[n] == '0' ) 
      division();
    else{
      if( x[n-1] == '0' ) 
        resta();
      else
        suma();
    }
  }
  cout << o ;
  return 0;
}