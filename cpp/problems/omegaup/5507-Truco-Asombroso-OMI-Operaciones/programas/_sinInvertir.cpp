#include <bits/stdc++.h>
using namespace std;

int ceros(string str){
  int i = 0;
  for(auto c:str) 
    if(c == '0')
      i++;
  return i;
}

int main(){
  int n, t, p=0; cin >> n;
  string x; cin >> x;
  //reverseStr(x, n);

  while(n > 0){
    p++;
    //printf("[%d] (%c) ", n, x[n]);
    cout << x << " - ";
    if(x[n] == '0') n--;
    else {
      string S=x, R=x;
      // restar
      R[n] = '0';
      int r=ceros(R);

      // sumar
      for(int i = n; i >=0 ; i--){
        if(S[i] == '0'){
          S[i] = '1';
          break;
        } else {
          S[i] = '0';
          if(i > 0 && S[i-1] == '0'){
            S[i-1] = '1';
            break;
          }
          else if(i == 0)
            S.insert(S.begin(), '1');
        }
      }
      int s=ceros(S);
      //cout << endl;
      printf("S: %d:", s); cout << S << endl;
      printf("R: %d: ", r); cout << R << endl;
      if(s>r && x != "11"){
        //printf("Sumar ");
        x=S;
      }else{
        //printf("Restar ");
        x=R;
      }

    }
    cout << x << endl;
  }

  cout << p;
  return 0;
}