#include <iostream>
using namespace std;

int n, P[1005], memo[1005][1005];
int chocolates(int ini, int fin){
    if( memo[ini][fin] > 0 ) return memo[ini][fin];
    if(ini == fin) return n*P[ini];
    int dias = n-(fin-ini);
    return memo[ini][fin] = max(
        chocolates(ini+1, fin)+P[ini]*dias,
        chocolates(ini, fin-1)+P[fin]*dias
    );
}

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> P[i];
    cout << chocolates(1, n);
    
    return 0;
}
