#include<stdio.h>





int main(){
    long long int n,m,k,x,y,mx,my,min,v,maxh,maxv,t,res;
    n=m=k=x=y=mx=my=min=v=maxh=maxv=t=res=0;
    char lm=0;
    scanf("%lld %lld %lld %lld %lld",&n,&m,&k,&mx,&my);

    if(mx>my){
        t=my;
        my=mx;
        mx=t;
        t=n;
        n=m;
        m=t;
    }

    v=(k/(((m-1)*mx)+my)*m);
    if(k%(((m-1)*mx)+my)!=0){
        res=k%(((m-1)*mx)+my);
        v+=res/mx;
    }
    printf("%lld",v+1);

}