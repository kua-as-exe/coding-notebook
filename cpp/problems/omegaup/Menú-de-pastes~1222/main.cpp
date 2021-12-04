#include <iostream>
using namespace std;
long long n, m, p, x, stade;

int main(){
  cin.tie(0); ios_base::sync_with_stdio(0);
  
  cin >> n >> m >> p;
  while( p-- ){
    cin >> x;
    
    stade = x/n+1;
    if( x%n == 0 )
    	stade -= 1;
    
    cout << stade + m * ( n * stade - x )  << " ";

  }

}
