[L1, T1] = list(map(int, input().split()))
[L2, T2] = list(map(int, input().split()))

if(L1 > L2 and T1 > T2):
  print("Hueso 1")
elif(L2 > L1 and T2 > T1):
  print("Hueso 2")
else:
  print("Perrito confundido :(")