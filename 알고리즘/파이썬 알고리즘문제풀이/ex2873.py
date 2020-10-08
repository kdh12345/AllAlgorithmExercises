import sys
dx=[-1,0,1,0]
dy=[0,1,0,-1]
r,c=map(int,sys.stdin.readline().split())
maps=[]
for i in range(r):
   arr=list(map(int,sys.stdin.readline().split()))
   maps.append(arr)
nx=0
ny=0
ans=""
if r%2==1:
    ans=(('R'*(c-1)+'D'+'L'*(c-1)+'D')*(r//2)+'R'*(c-1))
elif c%2==1:
    ans=(('D'*(r-1)+'R'+'U'*(r-1)+'R')*(c//2)+'D'*(r-1))
elif r%2==0 and c%2==0:
    low=1001
    pos=[-1,-1]
    for i in range(r):
        if i%2==0:
            for j in range(1,c,2):
                if low>maps[i][j]:
                    low=maps[i][j]
                    pos=[i,j]
        elif i%2==1:
            for j in range(c,2):
                if low>maps[i][j]:
                    low=maps[i][j]
                    pos=[i,j]
    ans=('D'*(r-1)+'R'+'U'*(c-1)+'R')*(pos[1]//2)
    x=2*(pos[1]//2)
    y=0
    x_bound=2*(pos[1]//2)+1
    while x!=x_bound and y!=r-1:
        if x!=x_bound and [y,x_bound]!=pos:
            x+=1
            ans+='R'
        elif x==x_bound and [y,x_bound-1]!=pos:
            x-=1
            ans+='L'
        if y!=r-1:
            y+=1
            ans+='D'
    ans=('R'+'U'*(r-1)+'R'+'D'*(r-1))*((c-pos[1]-1)//2)
print(ans)






