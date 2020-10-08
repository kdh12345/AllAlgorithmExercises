import sys
from collections import deque
n,m=map(int,sys.stdin.readline().split())
board=[]
dq=deque()
visit=[[0]*m for _ in range(n+1)]
dx=[-1,0,1,0]
dy=[0,1,0,-1]
def bfs():
    global dq
    global visit
    x=y=0
    dq.append((0,0))
    visit[0][0]=1
    while dq:
        x,y=dq.popleft()
        if x==n-1 and y==m-1:
            return visit[x][y]
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<n and 0<=ny<m:
                if board[nx][ny]==1 and visit[nx][ny]==0:
                    visit[nx][ny]=visit[x][y]+1
                    dq.append((nx,ny))
    return visit[x][y]

for i in range(n):
    arr=list(map(int,sys.stdin.readline().rstrip()))
    board.append(arr)


ans=-1
ans=bfs()
print(ans)