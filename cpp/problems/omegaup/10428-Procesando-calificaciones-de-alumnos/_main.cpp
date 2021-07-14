#include <bits/stdc++.h>
using namespace std;

long long int n, c, i, j, t;
vector <int> x;
string s;

int main(){
  cin >> n;
    while (n--){
    cin >> s;

    if(s == "REGISTRA"){
        cin >> t;
        x.push_back(t);
    }else if( s == "CUENTA" ){
        cin >> c >> i >> j;
        
        t = 0;
        for(long long a = i; a <= j; a++)
            if(x[a-1] == c)
                t++;
        
        cout << t << "\n";

    }

  }
  return 0;
}
