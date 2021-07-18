#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;

//int cartas[1010];
int main(){
    long long int k,n,m,x,maxK,L,r,temp;
    k=n=m=x=maxK=L=r=temp=0;
    
    
    bool casOMIJ=false;
    
    cin>>n>>k;
    int cartas[k+10];
    
    //scanf("%lld %lld",&n,&k);
    for(int i=0;i<k;i++){
        scanf("%d",&cartas[i]);
    }
    

    sort(cartas+0,cartas+k);
    /*for(x=0;x<k;x++){
        printf("%d ",cartas[x]);
    }*/
    maxK=cartas[k-1];
    L=n-maxK;
    if(cartas[0]==cartas[k-1]){
        casOMIJ=true;
    }

    if(casOMIJ==true){
        printf("%lld",L);
    }
    else{
        temp=pow(maxK,(k-1));
        temp= temp%1000009;

        r=(L*((k)*(temp))%1000009)%1000009;
        r+=L;
        printf("%lld",r);
    }
    return 0;
}
