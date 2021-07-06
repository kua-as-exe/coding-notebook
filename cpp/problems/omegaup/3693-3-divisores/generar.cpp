#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/* 
//Criba sacada de internet

vector<bool> isPrime;
vector<int> primes;
void criba(int n) {
    isPrime = vector<bool>(n, true);
    primes = vector<int>();
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int h=2; h*i<n; ++h) isPrime[i*h] = 0;
        }
    }
} */

int divi(int n){
    int x=0,div=0;
    for(x=1;x<=n;x++){
        if(n%x==0){
            div++;
        }
    }
    return div;
}

int main(){
    int x,n,k,a,b, ans;
    x=k=n=ans=0;

    scanf("%d %d ",&a,&b);
    /* printf(" %d - %d ", a, b); */
    for(x=a;x<=b;x++){
      int d = divi(x);
      if(d == 3) {
        ans++;
        int y =  sqrt(x);
        printf("\e[1;32m%d \e[0m(%d)\n",x, y);
      }
    }
    cout << ans << endl;

    /* criba(b);
    for(auto i in primes){
      printf("%d\n", i);
    } */
    
    return 0;
}
