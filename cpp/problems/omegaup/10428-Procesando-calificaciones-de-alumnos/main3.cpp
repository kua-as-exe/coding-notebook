#include <bits/stdc++.h>
using namespace std;

int n, c, i, j, t, r=1, m, a, b;
vector <int> x[105];
string s;

int busqueda(vector <int> y, int k){
    long long ini = 0, fin = y.size()-1;
    if( k < y[ini] ) return -1;
    if( k > y[fin] ) return -1;
    while(ini != fin){
        m = (ini+fin)/2;
        if( y[m] < k ) ini = m+1;
        else fin = m;
    } 
    return ini;
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

        cin >> c >> i >> j;
        printf("Buqueda en %d: %d a %d\n", c,  i, j);
        c--;
        a = busqueda(x[c], i);
        b = busqueda(x[c], j);
        if( x[c][b] > j ) b--;
        printf("[%d, %d]\n", a, b);

        int r = x[c][b];
        if( a != -1 && a < b ) r -= x[c][a];
        if( a == b ) r --;
        printf("R: %d\n", r);
        cout << b-a << "\n";

    }

  }
  return 0;
}
