def bubbleSort(arr): 
    n = len(arr[0]) 
    for i in range(n): 
        for j in range(0, n-i-1): 
            if arr[0][j] > arr[0][j+1] : 
                arr[0][j], arr[0][j+1] = arr[0][j+1], arr[0][j] 
                arr[1][j], arr[1][j+1] = arr[1][j+1], arr[1][j] 
            elif arr[0][j] == arr[0][j+1]:
                if arr[1][j] > arr[1][j+1]:
                    arr[0][j], arr[0][j+1] = arr[0][j+1], arr[0][j] 
                    arr[1][j], arr[1][j+1] = arr[1][j+1], arr[1][j] 
        
for _ in range(int(input())):
    n=int(input())
    xy=[[],[]]
    for i in range(n):
        x,y=map(int,input().split())
        xy[0].append(x)
        xy[1].append(y)
    #print(xy)
    bubbleSort(xy)
    #print(xy)
    x=0
    y=0
    ans=""
    flag=1
    for i in range(n):
        if(xy[0][i]>=x):
            ans+="R"*(xy[0][i]-x)
            x=xy[0][i]
        else:
            flag=0
            break
        if(xy[1][i]>=y):
            ans+="U"*(xy[1][i]-y)
            y=xy[1][i]
        else:
            flag=0
            break
    if flag==0:
        print("NO")
    else:
        print("YES")
        print(ans)