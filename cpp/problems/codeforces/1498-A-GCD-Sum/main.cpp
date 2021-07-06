#include <bits/stdc++.h>
using namespace std;

//nice
long long digitSum(long long n){
  long long total=0;
  while(n){
    total+=n%10;
    n/=10;
  }
  return total;
}

int main(){
  long long int n, t;
  cin >> n;
  while(n--){
    cin>>t; // is t okay?we have to run it to see
    while(1){
      if( __gcd(t,digitSum(t)) > 1 ){
        cout<<t<<endl;
        break;
      }
      t++;
    }
  }

  return 0;
}