#include <bits/stdc++.h>
using namespace std;

void reverseStr(string& str, int n){  
  for (int i = 0; i < n / 2; i++)
    swap(str[i], str[n - i - 1]);
}

int getCeros(string str){
  int i = 0;
  for(auto c:str){
    if(c == '0') i++;
    else break;
  } 
  return i;
}

int main(){
  int n, t, p=0; cin >> n;
  string x; cin >> x;
  reverseStr(x, n);
  int ceros = getCeros(x);

  while(x!="1"){
    //printf("[%d] (%c) ", i, x[i]);
    //cout << x << " - ";
    p++;
    if(x[0] == '0')
      x=x.substr(1);
    
    else {
      string S=x, R=x;
      R[0] = '0';
      int r=ceros+1;

      int s=ceros;
      int l = S.length();
      for(int i = 0; i < l; i++){
        if(S[i] == '0'){
          S[i] = '1';
          s--;
          break;
        } else {
          S[i] = '0';
          s++;
          if(S[i+1] == '0' && i < l-1){
            S[i+1] = '1';
            s--;
            break;
          }
          else if(i == l-1){
            S.push_back('1');
            s--;
          }
        }
      }

      if(s>r && x != "11") x=S;
      else x=R;
    } 
  }
  //cout << x << endl;
  cout << p;
  return 0;
}