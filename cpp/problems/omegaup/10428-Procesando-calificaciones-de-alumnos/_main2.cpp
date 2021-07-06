#include <bits/stdc++.h>
using namespace std;

long long int n, c, i, j, t, r=1, m, a, b;
vector <int> x[105];
string s;

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
        c--;

        


        a = 0; b = x[c].size()-1; t = -1;
        while(a <= b && t == -1){
            m = (a+b)/2;
            if(x[c][m-1] < i && x[c][m] >= i) t = m;
            else if(x[c][m] > i) b = m-1;
            else if(x[c][m] < i) a = m+1;
        }
        printf("i: %lld %lld: %lld\n", a, b, t);
       

        a = 0; b = x[c].size()-1; t = -1;
        while(a <= b && t == -1){
            m = (a+b)/2;
            if(x[c][m-1] < j && x[c][m] >= j) t = m;
            else if(x[c][m] > j) b = m-1;
            else if(x[c][m] < j) a = m+1;
        }
        printf("j: %lld %lld: %lld\n", a, b, t);

        printf("R: %lld\n", j-i);
        /* cout << j-i << "\n"; */

    }

  }
  return 0;
}
