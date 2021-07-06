n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
flag = 1

for i in range(n):
  if(a[i] <= b[i]):
    flag = 0

print(flag)