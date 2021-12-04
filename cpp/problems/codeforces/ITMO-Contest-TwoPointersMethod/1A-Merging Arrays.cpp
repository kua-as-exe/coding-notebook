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

  int i = 0, j = 0;
  while( i < n || j < m ){
    if( j == m || ( i < n && a[i] < b[j] ) ){
        cout << a[i] << " ";
        i++;
    }else{
        cout << b[j] << " ";
        j++;
    }

    /* if ( ( i < n && a[i] < b[j]) || j == m) { */
    /*   cout << a[i] << " "; */
    /*   i++; */
    /* } */
    /* if ( (j < m && b[j] <= a[i]) || i == n ){ */
    /*   cout << b[j] << " "; */
    /*   j++; */
    /* } */

  }

  return 0;
}
