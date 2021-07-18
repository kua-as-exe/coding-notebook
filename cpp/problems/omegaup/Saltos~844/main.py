import math

def mcm(x, y):
  return (x*y)/math.gcd(x, y)

m, n = map(int, input().split(" "))
a, d = map(int, input().split(" "))
f, c = map(int, input().split(" "))

print(int(mcm( int(mcm(m, a)/a), int(mcm(n, d)/d)) ))