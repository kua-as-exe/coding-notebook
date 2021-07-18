#include <bits/stdc++.h>
using namespace std;

string sikiniano(string text){
  if(text.size() == 1) return text;
  if(text.size() == 2) {
   char t = text[0];
   text[0] = text[1];
   text[1] = t;
   return text; 
  };
  long int l = text.size();
  long int m = l/3;
  string a = sikiniano(text.substr(0, m));
  string b = sikiniano(text.substr(m, l-m*2));
  string c = sikiniano(text.substr(l-m, l));
  return b+c+a;
}

int main(){
  string s;
  cin >> s;
  cout << sikiniano(s);
  return 0;
}