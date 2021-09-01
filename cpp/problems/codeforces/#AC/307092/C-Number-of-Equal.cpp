#include <iostream>
using namespace std;

int n, m;
long long int a[100005], b[100005];

int main(){
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for( int i = 0; i < m; i++ ){
    cin >> b[i];
  }

  int i = 0; 
  long long int localPairs = 0, pairs = 0;
  for(int j = 0; j < m; j++){

    if( j == 0 || b[j] != b[j-1] ){
      localPairs = 0;
      while( i < n && a[i] <= b[j] ){
        if(a[i] == b[j])
          localPairs++;
        i++;
      }
    }
    pairs += localPairs;

  }

  cout << pairs;

  return 0;
}
