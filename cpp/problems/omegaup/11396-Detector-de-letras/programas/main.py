s=list(input().split())
o=[]

characters=0
limit=10
vowels=['A', 'E', 'I', 'O', 'U']

for c in s:
  if(c >= 'A' and c <= 'Z'):
    vowel=False
    for v in vowels:
      if(c == v): 
        vowel=True
    
    if(c == 'Y'): 
      o.append('S')
    elif(vowel): 
      o.append('V')
    else: 
      o.append('C')

print(" ".join(o))
