from random import randint
from glob import glob
files=glob('*.in')

minN=1000
maxN=1000

minX=1
maxX=1000
#n = int(input("Cantiad de elementos: "))
n=randint(minN, maxN)
#w = int(input("Número a buscar: "))
l = []

def r (): return randint(minX, maxX)

t=r()
for _ in range(n):
  l.append(t)
  t+=r()

caseFilesPrefix=str(len(files)+1)
i=open(caseFilesPrefix+".in", "w+")
i.write(str(n)+"\n")
print(n)

numberList=" ".join(map(str, l))
i.write(numberList+"\n")
print(numberList)

last=l[-1:][0]
w=randint(minX, last)
print(w)
i.write(str(w)+"\n")

i.close()
index=-1
if w in l:
  index=l.index(w)
print(index)

o=open(caseFilesPrefix+".out", "w+")
o.write(str(index))
o.close()
