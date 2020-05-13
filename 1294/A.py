for _ in range(int(input())):
    a,b,c,n=map(int,input().split())
    x=(a+b+c+n)//3
    A=x-a
    B=x-b
    C=x-c
    if(A+B+C==n):
        print("YES")
    else:
        print("NO")