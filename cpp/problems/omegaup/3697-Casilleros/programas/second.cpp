#include <bits/stdc++.h>
using namespace std;

float sqrt3(const float& n)
{
   static union {int i; float f;} u;
   u.i = 0x2035AD0C + (*(int*)&n >> 1);
   return n / u.f + u.f * 0.25f;
}

int main(){
  int n, x;
  cin >> n;
  x = sqrt3(n);
  cout << x;
  return 0;
}