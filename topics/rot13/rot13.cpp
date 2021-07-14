#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string rot( string t, int rot){
  for(char &c: t){
    char offset = 0;
    if( c >= 'a' && c <= 'z' )
      offset = 'a'; // if is lower
    else if( c >= 'A' && c <= 'Z' )
      offset = 'A'; // if is upper
    else continue; // continue if is not letter

    c = (c-offset+rot)%26 + offset;

  }
  return t;
}

int main(){
  string text;
  do {
    getline(cin, text);
    cout << rot(text, 13) << endl;
  } while (!text.empty());
}
