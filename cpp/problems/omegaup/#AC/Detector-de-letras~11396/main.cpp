#include <iostream>
using namespace std;

int characters = 0, limit = 10;
char vowels[5] = {'A', 'E', 'I', 'O', 'U'};

void check(){
  char c;
  cin >> c;
  bool vowel = false;
  if(c >= 'A' && c <= 'Z'){
    for (char v : vowels)
      if(c == v) vowel = true;
    
    if(c == 'Y') cout << 'S';
    else if(vowel) cout << 'V';
    else cout << 'C';
    if(characters < limit-1) cout << " ";
    characters++;
  }
}

int main(){
  char t;
  while (characters < limit)
    check();

  return 0;
}