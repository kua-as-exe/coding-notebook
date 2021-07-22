n, m, k, x, y = map(int, input().split(" "))
v=0
if x > y:
  x, y = y, x
  n, m = m, n
pisos = min(int(k/(y+x*(m-1))), n-1)

if pisos > 0:
  v += pisos*m
  k -= pisos*(m-1)*x + (pisos)*y

v += min(int(k/x), m-1);
print(v+1)