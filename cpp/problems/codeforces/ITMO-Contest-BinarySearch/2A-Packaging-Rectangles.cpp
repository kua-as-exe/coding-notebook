#include <iostream>
using namespace std;

#define ulli unsigned long long int

ulli w, h, n;

bool p(ulli x){
    if( (x/w)*(x/h) >= n ) return true;
    return false;
}

int main(){
    std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false);

    cin >> w >> h >> n;
    ulli i = 0, f = max(w, h)*n, m;

    while( i <= f ){
        m = (i+f)/2;
        if( p(m) ) f = m-1;
        else i = m+1;
    }
    cout << i;

    return 0;
}
