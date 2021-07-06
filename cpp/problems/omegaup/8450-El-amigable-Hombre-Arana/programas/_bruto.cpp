#include<stdio.h>




int main(){
    long long int n,m,k,x,y,mx,my,min,v,maxh,maxv;
    n=m=k=x=y=mx=my=min=v=maxh=maxv=0;
    char lm=0;
    scanf("%lld %lld %lld %lld %lld",&n,&m,&k,&mx,&my);

    if(mx>my){
        while(k>0){
        maxv++;
        if(maxv>n-1){
            maxv=0;
            k-=mx;
            //printf("siuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu %d\n",k);
            if(k<0){
                break;
            }
            v++;
        }
        else{

            k-=my;
           //printf("noooooooooooooooooooooooooooo %d\n",k);
            if(k<0){
                break;
            }
            v++;
            }
        }
    }
    else{
        while(k>0){
        maxh++;
        if(maxh>m-1){
            maxh=0;
            k-=my;
            //printf("siuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu %d\n",k);
            if(k<0){
                break;
            }
            v++;
        }
        else{

            k-=mx;
            //printf("noooooooooooooooooooooooooooo %d\n",k);
            if(k<0){
                break;
            }
            v++;
            }
        }
    }

    printf("%lld",v+1);
    return 0;



}
