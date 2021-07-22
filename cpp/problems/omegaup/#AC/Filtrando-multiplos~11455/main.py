n = int(input())
a = list(input().split())
k = int(input())

for i in range(n):
  if(int(a[i])%k != 0):
    a[i] = 'X'

print(" ".join(a))