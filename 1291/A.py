# cook your dish here
for _ in range(int(input())):
    n=int(input())
    s=input()
    sm=0
    for ch in s:
        sm+=(int)(ch)
    i=n-1
    while not(sm%2==0 and int(s[i])%2!=0) and i>=0:
        sm-=(int)(s[i])
        i-=1
    if i>=0:
        ans=""
        for j in range(0,i+1):
            ans+=s[j]
        print(ans)
    else:
        print("-1")