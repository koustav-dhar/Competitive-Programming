n,k=map(int,input().split())
p=list(map(int,input().split()))
i1=0
i2=0
count=1
sum=n*(n+1)//2-(n-k)*(n-k+1)//2
c=0
for i in range(0,n):
    if n-k+1<=p[i]:
        i1=i
        break
for i in range(n-1,-1,-1):
    if n-k+1<=p[i]:
        i2=i
        break
#print(i1,i2)
for i in range(i1+1,i2+1):
    if n-k+1<=p[i]:
        c+=1
        count=((count%998244353)*(c%998244353))%998244353
        c=0
    else:
        c+=1
print(str(sum)+" "+str(count))