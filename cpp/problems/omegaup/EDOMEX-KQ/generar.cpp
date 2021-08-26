#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define lli long long int

unsigned int N;

vector <unsigned long int> multArray;

lli multiplos(unsigned int x){
  if(multArray[x] > 0) return multArray[x]; 
  lli count = 0;
  for( unsigned int i = 1; i <= x; i++ )
    if( x%i == 0 )
      count++;
  multArray[x] = count;
  return count;
}
int main(){

  multArray.resize(10000000);
  cin >> N;
  /* cout << multiplos(N); */
  printf("{ ");
  for(int i = 0; i < N; i++){
    printf("%lld", multiplos(i));
    if( i < N-1 )
      printf("");
  }
  printf("}");
  return 0;
}
