for _ in range(int(input())):
    n=int(input())
    s=input()
    x=0
    y=0
    for c in s:
        if c=='L':      x-=1
        elif c=='R':    x+=1
        elif c=='U':    y+=1
        elif c=='D':    y-=1
    xx=0
    yy=0
    l=[]
    for i in range(len(s)):
        if s[i]=='L':      xx-=1
        elif s[i]=='R':    xx+=1
        elif s[i]=='U':    yy+=1
        elif s[i]=='D':    yy-=1
        #print(xx,yy)
        if x==xx and y==yy:
            l.append(i+1)
    if(len(l)==1 and (x!=0 or y!=0)):
        print("-1")
    else:
        if x==0 and y==0:
            l.insert(0,0)
        #print(l)
        mindist=10**9+7
        mins=-1
        minl=-1
        dist=[]
        for i in range(len(l)-1):
            dist.append(l[i+1]-l[i]-1)
            if(dist[i]<mindist):
                mins=l[i]+1
                minl=l[i+1]
                mindist=dist[i]
        #print(dist)
        print(mins,minl)