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
    lli t = x[s];
    for(lli i = s+1; i <= e; i++)
       t ^= x[i];
    
    return t;
}

int main(){
cout << endl;
  cin >> n;
  input();
  for(lli i = 1; i < n; i++) {
      input();
  }
  
    /* printV(); */
   
    /* for(lli i = 1; i < n; i++){ */
    /*     x[i] ^= x[i-1]; */
    /* } */

    for(lli l = n-1; l >= 1; l--){
       
        for(lli k = 0; k < n-l; k++){
            lli r = range(k, k+l);
            if(r == 0){
                /* printf("%lld - %lld: %lld\n", k, k+l, r); */
                c++;
            }

        }

    }

    /* printV(); */
    cout << c; 
  return 0;
}
