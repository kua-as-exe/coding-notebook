#include<stdio.h>
#include<math.h>




int main(){
    long long int x,n,k,a,i,m,b,y,dou;
    x=k=n=i=a=m=b=y=dou=0;

    long long int rz=0;

    scanf("%d %d",&a,&b);
    long long int lim=sqrt(b)+1;
    bool criba[lim+10];
    //printf("rip\n");
    for(x=0;x<n;x++){
        criba[x]=false;
    }

    for(x=2;x<lim;x++){
        //printf("Checando para %d\n",x);

        if(criba[x]==false){

           // printf("vamos\n");
            m=0;
            for(y=2;m<lim;y++){
                m=x*y;
                if(m>lim){
                    break;
                }
                //printf("%d desaparecido, atte los z's\n",m);
                criba[m]=true;
            }
            dou=x*x;
            if(a<=dou&&dou<=b){
                //printf("%d\n",x);
                i++;
            }
        }
    }

    /*for(x=0;x<b;x++){
        //printf("que");
        if(criba[x]==false){
            printf("%d\n", x);
        }

    }*/

    /*for(x=a;x<b;x++){
        rz=sqrt(x);
        if(rz*rz==x){
            if(criba[rz]==false){
                //printf("found %lld\n",x);
                i++;
            }
        }
    }


    /*for(x=a;x<=b;x++){
        n=divi(x);
        if(n==k){
        }            i++;


    }*/
    printf("%lld",i);

    return 0;
}
