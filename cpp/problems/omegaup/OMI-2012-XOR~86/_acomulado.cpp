#include <bits/stdc++.h>
using namespace std;

#define lli long long int

long long int n, t, c;
vector <long long int> x;

void printV(){
    for(auto i = x.begin(); i != x.end(); ++i)
        cout << *i << "\t";
    cout << endl;
}

void input(){
    long long int t;
    cin >> t;
    x.push_back(t);
}

lli range(lli s, lli e){
    t = x[e];
    if(s > 0) t ^= x[s-1];
    return t;
}

int main(){
     std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);


cout << endl;
    cin >> n;
 
  input();
  for(lli i = 1; i < n; i++){
      input();  
      x[i] ^= x[i-1];
  }  

    /* printV(); */
    
    for(lli l = n-1; l >= 1; l--){
       
        for(lli k = 0; k < n-l; k++){

            lli r = range(k, k+l);
            if(r == 0){
                /* printf("%lld - %lld: %lld\n", k, k+l, r); */
                c++;
            }

        }

    }

    cout << c; 
  return 0;
}
