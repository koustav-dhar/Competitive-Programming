# your code goes here
mod=998244353
n=int(input())
prev=[0]*(n+3)
val=[0]*(n+2)
s=[0]*(n+2)
for i in range(n,0,-1):
	s[i]=(s[i+1]+prev[i+2]+2*val[i+1])%mod
	val[i]=((n-i+1)*pow(10,n-i+1,mod)-s[i])%mod
	prev[i]=(prev[i+1]+val[i])%mod
for i in range(1,n+1):
	print(val[i],end=" ")