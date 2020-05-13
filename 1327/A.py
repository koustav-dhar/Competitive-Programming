# your code goes here
import math
for _ in range(int(input())):
    n,m=map(int,input().split())
    if n%2==0:
        if m%2==0:
            if m<=((int)(math.sqrt(n))):
                print("YES")
            else:
                print("NO")
        else:
            print("NO")
    else:
        if m%2!=0:
            if m<=((int)(math.sqrt(n))):
                print("YES")
            else:
                print("NO")
        else:
            print("NO")