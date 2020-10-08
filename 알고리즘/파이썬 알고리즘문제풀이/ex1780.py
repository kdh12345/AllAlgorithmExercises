import sys
n=int(sys.stdin.readline().rstrip())
maps=[]
for _ in range(n):
    arr=list(map(int,sys.stdin.readline().split()))
    maps.append(arr)
ans=[0,0,0]
def chk(x,y,siz):
    global ans
    num=maps[x][y]
    flag=True
    for i in range(siz):
        for j in range(siz):
            if maps[x+i][y+j]!=num:
                flag=False
                break
    return flag,num

def go(siz,x,y):
    global ans
    possible,res=chk(x,y,siz)
    if possible:
        ans[res+1]+=1
    else:
        for i in range(3):
            for j in range(3):
                go(siz//3,x+i*(siz//3),y+j*(siz//3))
go(n,0,0)
print(ans[0])
print(ans[1])
print(ans[2])