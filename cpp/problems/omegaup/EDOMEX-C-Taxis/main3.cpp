#include <functional>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <stdio.h>

bool _debug = true;
#define DEBUG if( _debug )

using namespace std;

long long int taxisCount, a, b;
long int passengers, passList[100005];

struct taxi{
  long int n;
  long long int a, b;
};

vector <taxi> taxi_queue;

stack <long long int> available;

long long int newTaxi(){
  DEBUG printf(" New Taxi %lld\n", taxisCount+1);
  taxisCount++;
  return taxisCount;
}

void takeTaxi(long int taxiI, long long int _a, long long int _b, long int passI){
  DEBUG printf(" Taxi %ld taken from %lld to %lld\n", taxiI, _a, _b);
  passList[passI] = taxiI;
  taxi_queue.push_back({taxiI, _a, _b});
}

int main(){
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  cin >> passengers;

  for(long int i = 1; i <= passengers; i++){
    cin >> a >> b;
    DEBUG printf("Passenger %ld (%lld, %lld):\n", i, a, b);
    
    /* while( !taxi_queue.empty() && taxi_queue.back().b <= a ){ */
    for( long long int v = 0; v < taxi_queue.size(); v++){
      if( taxi_queue[v].b < a ){
        available.push( taxi_queue[v].n );
        DEBUG printf(" Taxi %ld available\n", taxi_queue[v].n);
        taxi_queue.erase(taxi_queue.begin()+v);
      } 
    }

    if( available.empty() ) takeTaxi(newTaxi(), a, b, i);
    else {
      long long int k = available.top();
      takeTaxi(k, a, b, i); 
      available.pop();
    }

  }

  DEBUG while( !taxi_queue.empty() ){
    taxi T = taxi_queue.back();
    DEBUG printf("%ld (%lld, %lld)\n", T.n, T.a, T.b);
    taxi_queue.pop_back();
  }
    
  cout << taxisCount << "\n";
  for( long int i = 1; i <= passengers; i++){
    cout << passList[i] << " ";
  }

  return 0;

}
