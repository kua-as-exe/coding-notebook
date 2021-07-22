n = int(input())

for i in range(n):
  for j in range(n):
    c=' ';
    if(i == j or i == (n-j-1)): c = '@'
    print(c, end='')  
  print()