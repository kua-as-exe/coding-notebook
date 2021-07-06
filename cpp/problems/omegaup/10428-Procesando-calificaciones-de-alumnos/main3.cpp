#include <bits/stdc++.h>
using namespace std;

long long int n, c, i, j, t, r=1, m, a, b;
vector <long long int> x[105];
string s;

int busqueda(vector <long long int> y, long long k){
    a = 0; b = y.size()-1;
    while(a != b){
        m = (a+b)/2;
        if( y[m] < k ) a = m+1;
        else b = m;
    } 
    return a;
}

int main(){
  cin >> n;
    while (n--){
    cin >> s;

    if(s == "REGISTRA"){
        cin >> c;
        x[c-1].push_back(r);
        r++;
    }else if( s == "CUENTA" ){

        printf("\n");
        for(int z = 0; z < 100; z++){
            if(x[z].size() > 0){
                printf("%d: ", z+1);
                for( auto q : x[z] )
                    cout << q << ", ";
                printf("\n");
            }
        }
        printf("\n");

        cin >> c >> i >> j;
        c--;
        printf("Buqueda: %lld a %lld\n", i, j);
        a = busqueda(x[c], i-1);
        b = busqueda(x[c], j);

        printf("[%lld, %lld]\n", a, b);
        printf("R: %lld\n", b-a);
        cout << b-a << "\n";

    }

  }
  return 0;
}
