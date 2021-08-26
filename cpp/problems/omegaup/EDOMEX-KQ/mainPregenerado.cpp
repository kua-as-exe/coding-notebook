#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

#define lli long long int
#define li long int
#define ui unsigned int

unsigned int N, K, Q;

vector <unsigned int> multArray;
vector <unsigned int> numbers;
vector <lli> numbersMults;

lli multiplos(int x){
  if(multArray[x] > 0) return multArray[x]; 
  lli count = 0;
  for( int i = 1; i <= x; i++ )
    if( x%i == 0 )
      count++;
  multArray[x] = count;
  return count;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  cin >> N >> K >> Q;

  multArray.resize(10000000);
  numbers.resize(N+1);
  numbersMults.resize(N+1);

  for(int i = 0; i < N; i++){
    cin >> numbers[i];
    numbersMults[i] = multiplos(numbers[i]);
    /* printf("%d: %lld\n", numbers[i], numbersMults[i]); */
  } 
  
  ui res = 0;
  for(ui l = N; l >= K; l--){
    for( ui a = 0; a <= N-l; a++){
      ui count = 0;
      bool exit = false;
      for( ui i = a; i < a+l; i++ ){
         if( numbersMults[i] >= Q )
           count++;
         if( count > K ){
           exit = true;
           break;
         }
      }
      if( exit ) continue;
      if( count == K )
        res ++;
    }
  }
  cout << res;

  return 0;
}
