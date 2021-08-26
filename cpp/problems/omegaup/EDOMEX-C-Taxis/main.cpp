#include <functional>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <stdio.h>

bool _debug = false;
#define DEBUG if( _debug )

using namespace std;

long long int taxisCount, a, b;
long long int passengers = 1, passList[100015];

struct taxi{
  long long int n, a, b;
};

auto cmp = [](taxi left, taxi right) {
  return (left.b) > (right.b);
};
priority_queue<taxi, vector<taxi>, decltype(cmp)> events(cmp);

stack <long long int> available;

long long int newTaxi(){
  DEBUG printf(" New Taxi %lld\n", taxisCount+1);
  taxisCount++;
  return taxisCount;
}

void takeTaxi(long long int taxiI, long long int _a, long long int _b, long long int passI){
  DEBUG printf(" Taxi %lld taken from %lld to %lld\n", taxiI, _a, _b);
  passList[passI] = taxiI;
  events.push({taxiI, _a, _b});
}

int main(){
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  cin >> passengers;

  for(long int i = 1; i <= passengers; i++){
    cin >> a >> b;
    DEBUG printf("Passenger %ld (%lld, %lld):\n", i, a, b);

    /* while (!events.empty()) { */
    while (!events.empty() && events.top().b < a) {
      available.push(events.top().n);
      DEBUG printf(" Taxi %lld available\n", events.top().n);
      events.pop();
    }

    if( available.empty() ) takeTaxi(newTaxi(), a, b, i);
    else {
      takeTaxi(available.top(), a, b, i); 
      available.pop();
    }

  }

  DEBUG while (!events.empty()) {
    taxi T = events.top();
    DEBUG printf("%lld (%lld, %lld)\n", T.n, T.a, T.b);
    events.pop();
  }

  cout << taxisCount << "\n";
  for( long int i = 1; i <= passengers; i++){
    cout << passList[i] << " ";
  }

  return 0;

}
