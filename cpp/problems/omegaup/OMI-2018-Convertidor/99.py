#!/usr/bin/python3
c=26
def _main() -> None:
  o = input()

  if o == "0":
    a = int(input())
    t=""
    while a > 0:
      if a%c > 0:
        t = chr( a%c+64 )+t
      else:
        t = 'Z'+t
        a -= 1
      a=int(a/c)
    print(t)
  elif o == "1":
    t = input()
    a = 0
    for i in range(len(t)):
      #print( ( ord(t[i])-64 )*( 26**(len(t)-i-1) ) )
      k = 26**(len(t)-i-1)
      a += ( ord(t[i])-64 )*k
    print(a)
    
  pass

if __name__ == '__main__':
  _main()
