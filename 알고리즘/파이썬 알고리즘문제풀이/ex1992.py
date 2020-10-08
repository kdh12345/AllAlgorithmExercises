import sys
n=int(sys.stdin.readline())
maps=[]
for i in range(n):
    arr=list(map(int,sys.stdin.readline().strip()))
    maps.append(arr)
def go(x,y,siz):
    cnt=0
    for i in range(x,x+siz):
        for j in range(y,y+siz):
            if maps[i][j]==1:
                cnt+=1
    if cnt==siz*siz:
        print(1,end='')
    elif cnt==0:
        print(0,end='')
    else:
        print("(",end='')
        go(x,y,siz//2)
        go(x,y+siz//2,siz//2)
        go(x+siz//2,y,siz//2)
        go(x+siz//2,y+siz//2,siz//2)
        print(")",end='')
    return
go(0,0,n)