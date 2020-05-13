for _ in range(int(input())):
    s=int(input())
    i=1
    x=0
    while s>=10:
        x+=10*(s//10)
        s=s-10*(s//10)+s//10
    x+=s
    print(x)