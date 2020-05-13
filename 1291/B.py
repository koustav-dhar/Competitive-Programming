for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    rightcheck=[0 for i in range(n)]
    leftcheck=[0 for i in range(n)]
    #check=[0 for i in range(n)]
    for i in range(n-1,0,-1):
        if(l[i]>=n-i-1):
            rightcheck[i]=1
        else:
            break
    for i in range(n-1):
        if(l[i]>=i):
            leftcheck[i]=1
        else:
            break
    check=[]
    for i in range(n):
        if i==0 or i==n-1:
            check.append(0)
        else:
            if (l[i-1]<l[i] and l[i]<l[i+1]) or (l[i-1]>l[i] and l[i]>l[i+1]):
                check.append(0)
            else:
                check.append(1)
    flag=0
    for i in range(1,n-1):
        if check[i]==1:
            if rightcheck[i]==1 and leftcheck[i]==1:
                flag=1
                #print(i)
                break
    if n==1:
        print("Yes")
    elif n==2:
        if l[0]==0 and l[1]==0:
            print("No")
        else:
            print("Yes")
    elif max(check)==0:
        print("Yes")
    elif flag==0:
        print("No")
    else:
        print("Yes")