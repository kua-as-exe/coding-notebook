import math

n = int(input())

def digitSum(x):
  total=0
  while(x):
    total += int(x%10)
    x/=10
  return total

for i in range(n):
  t=int(input())
  while(1):
    if( math.gcd(t, digitSum(t)) > 1 ):
      print(t)
      break
    t+=1