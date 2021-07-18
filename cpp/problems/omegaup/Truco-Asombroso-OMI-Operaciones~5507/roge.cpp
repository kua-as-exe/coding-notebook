#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

string bin;

void sumbin(){
    int i=bin.size()-1;
    while(true){
        if(i<0){
            bin.insert(bin.begin(),'1');
            break;
        }
        else{
            if(bin[i]=='0'){
                bin[i]='1';
                break;
            }
            bin[i]='0';
            i--;
        }
    }


    return;
}



int main(){
    int n=0,o=0;
    cin>>n>>bin;


    while(bin.size()!=1){
        if(bin.size()==2&&bin=="11"){
            o+=2;
            break;
        }
        n=bin.size();
        if(bin[n-1]=='0'){
            o++;
            bin.pop_back();
        }
        else if(bin[n-1]=='1'){
            if(bin[n-2]=='0'){
                o++;
                bin[n-1]='0';
            }
            else{
                sumbin();
                o++;
            }

        }
    }


    printf("%d", o);

    return 0;
}
