#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <initializer_list>
using namespace std;

#define s 100005
int N, M, K;
int n[s], m[s], k[s];

int main(){
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++)
        cin >> n[i];
    for(int i = 0; i < M; i++)
        cin >> m[i];
    for(int i = 0; i < K; i++)
        cin >> k[i];

    int mi = -1, d;

    int A, B, C;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            for(int c = 0; c < K; c++){
                initializer_list<int> e({n[a], m[b], k[c]});
                d = max(e)-min(e);
                if(mi == -1 || mi > d){
                    mi = d;
                    A = n[a];
                    B = m[b];
                    C = k[c];
                    //printf(" [%d, %d, %d] => %d\n", n[a], m[b], k[c], d);
                }
            }
        }
    }
    printf("%d %d %d", A, B, C);


}