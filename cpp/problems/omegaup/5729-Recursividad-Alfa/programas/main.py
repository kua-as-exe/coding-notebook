t={}
def f(n):
  if n < 50 : return 2;
  if n in t :
    return t[n]

  t[n] = f(n-1)+( f(n-5)*2 )
  return t[n]

n = int(input())
print(f(n))