#include <iostream>
#include <utility>
#include <vector>
#include <stack>
using namespace std;

int main(){
  cin.tie(0); ios_base::sync_with_stdio(false);

  long long int i, n, t, m = 0; cin >> n;
  stack< pair<int, int> > s;

  for( i = 0; i < n; i++){
    cin >> t;
    int prev = i;
    while( !s.empty() && s.top().first > t ){
      m = max(m, (i-s.top().second)*s.top().first );
      prev = s.top().second;
      s.pop();
    }
    s.push({ t, prev });
  }
  while( !s.empty() ){
    m = max(m, (n-s.top().second)*s.top().first );
    s.pop();
  }

  cout << m;

  return 0;
}
