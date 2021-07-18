#include<stdio.h>




int main(){
    long long int n,m,k,x,y,mx,my,mini,v,maxh,maxv,t,res;
    n=m=k=x=y=mx=my=mini=v=maxh=maxv=t=res=0;
    scanf("%lld %lld %lld %lld %lld",&n,&m,&k,&mx,&my);

    if(mx>my){
        t=my;
        my=mx;
        mx=t;
        t=n;
        n=m;
        m=t;
    }

    while(k>0){
    if(k-(mx*(m-1)+my)>=0){
        //printf("%d\n",k-(mx*(m-1)+my));
        k-=(mx*(m-1)+my);
        if(v+m>=m*n){
            v=m*n-1;
            break;
        }
        v+=m;
        //printf("%d\n",k);
        //printf("siuuuuuuuuuuuuuuu\n");
    }
    else{
        if(k/mx>=m-1){
            //printf("%d %d qqqqqqqqqqqqqqqqqqqqq\n",k,mx);
            v+=m-1;

            break;
        }
        v+=k/mx;
        break;
        //printf("nouuuuuuuuuuuuuuuuuuuuu\n");
    }
    }

    printf("%lld",v+1);
    return 0;

}