
def sikiniano(t):
  l = len(t)
  if l == 1 : return t
  if l == 2 : return t[1]+t[0]
  m = int(l/3)
  a=sikiniano(t[:m])
  b=sikiniano(t[m:-m])
  c=sikiniano(t[-m:])
  return b+c+a

text = input()
print(sikiniano(text))
