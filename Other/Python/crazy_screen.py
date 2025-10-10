import random as r
c = "~!@#$%^&*()_+`1234567890-=QWERTYUIOP}{|qwertyuiop[]ASDFGHJKL:asdfghjkl;'ZXCVBNM<>?zxcvbnm,./'"
n=92
le=339
while True:
    l=[]
    for i in range(le):
        p = r.randint(0,n)
        l.append(c[p])
    print(*l, sep='')