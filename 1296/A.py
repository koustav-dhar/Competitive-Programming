for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    s=sum(l)
    cev=0
    codd=0
    for i in range(n):
        if l[i]%2==0:
            cev+=1
        else:
            codd+=1
    if s%2!=0:
        print("YES")
    elif cev>0 and codd>0:
        print("YES")
    else:
        print("NO")