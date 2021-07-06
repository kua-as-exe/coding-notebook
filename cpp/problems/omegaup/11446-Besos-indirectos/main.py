n = int(input())
l = list(map(int, input().split(" ")))
#print(l)
x = False
# l = list([0] * (n+1))
# for i in range(n):
#   l[i]=t[i]

for a in range(1, n-1):
  b=l[a-1]
  c=l[b-1]
  if c != a and c != b :
    print(a, c)
    x=True

if x == False : 
    print("Esto no es tan divertido como parecia")
