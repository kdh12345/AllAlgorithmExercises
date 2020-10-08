import sys
from collections import deque
n=int(sys.stdin.readline().rstrip())
start=[]
maps=[[0]*2001 for _ in range(2002)]
visit=[[0]*2001 for _ in range(2002)]
dx=[-1,0,1,0]
dy=[0,1,0,-1]
def bfs(a,b):
    q=deque()
    q.append([a,b])
    visit[a][b]=1
    while len(q)!=0:
        x,y=q.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<=2000 and 0<=ny<=2000:
                if maps[nx][ny]==1 and visit[nx][ny]==0:
                    visit[nx][ny]=1
                    q.append([nx,ny])
for _ in range(n):
    x1,y1,x2,y2=map(int,sys.stdin.readline().split())
    #-구간을 0으로 만들고 2배로 늘임
    x1+=500
    y1+=500
    x2+=500
    y2+=500
    x1*=2
    y1*=2
    x2*=2
    y2*=2
    start.append([x1,y1])
    for i in range(x1,x2+1):
        if i==x1 or i==x2:
            for j in range(y1,y2+1):#직사각형 만드는 경로
                maps[i][j]=1
        else:
            maps[i][y1]=1
            maps[i][y2]=1
ans=0
for i in range(len(start)):
    sx,sy=start[i]
    if visit[sx][sy]==0:
       bfs(sx,sy)
       ans+=1
if maps[1000][1000]==1:#가운데가 1이면 직사각형 만들수 없다
    ans-=1
print(ans)