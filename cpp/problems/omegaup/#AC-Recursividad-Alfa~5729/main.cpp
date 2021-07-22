#include <stdio.h>

long long int c[115];

long long int func(int n){
  if(n < 50) return 2;
  if(c[n-50]) return c[n-50];
  c[n-50] = func(n-1)+( func(n-5)*2 );
  return c[n-50];
}

int main()
{
  int n;
  scanf("%d", &n);
  printf("%lld", func(n));

  return 0;
}