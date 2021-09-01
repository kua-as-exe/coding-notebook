#include <iostream>
using namespace std;

int n, m;
long long int a[100005], b[100005];

int main(){
  /* cin.tie(nullptr); */

  cin >> n >> m;

  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for( int i = 0; i < m; i++ ){
    cin >> b[i];
  }

  int i = 0;
  for(int j = 0; j < m; j++){
    
    while( a[i] < b[j] && i < n ){
      i++;
    }

    cout << i << " ";

  }

  return 0;
}
