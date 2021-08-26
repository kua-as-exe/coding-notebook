// MLE
#include <functional>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <stdio.h>

bool _debug = false;
#define DEBUG if( _debug )
using namespace std;

long long int taxisCount, a, b, last;
long int passengers, passList[100005];

stack <long int> timeline[100005];
stack <long int> available;

void takeTaxi(long int i, long int _k, long long int _b){
    DEBUG printf(" Taken taxi %ld\n", _k);
    passList[i] = _k;
    timeline[_b].push(_k);
}

int main(){

  cin >> passengers;

  for(long int i = 1; i <= passengers; i++){
    cin >> a >> b;
    DEBUG printf("Passenger %ld (%lld, %lld):\n", i, a, b);
    
    while( last < a ){
      DEBUG printf(" Checking time %lld: ", last);
      if( !timeline[last].empty() ){
        DEBUG printf(" Not void");
        while( !timeline[last].empty() ){
          DEBUG printf(" Taxi leaved %ld\n", timeline[last].top());
          available.push(timeline[last].top()); 
          timeline[last].pop();
        }
      }
      last++;
      DEBUG printf("\n");
    }
    /* last--; */

    if( !available.empty() ){
      takeTaxi(i, available.top(), b);
      available.pop();
    } else {
      taxisCount++;
      DEBUG printf(" New Taxi %lld\n", taxisCount);
      takeTaxi(i, taxisCount, b);
    }

  }
    
  cout << taxisCount << "\n";
  for( long int i = 1; i <= passengers; i++){
    cout << passList[i] << " ";
  }

  return 0;

}
