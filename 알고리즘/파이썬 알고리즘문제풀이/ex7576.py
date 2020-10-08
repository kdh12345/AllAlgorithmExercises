import sys
from collections import deque
m,n=map(int,sys.stdin.readline().split())
board=[]
dq=deque()
visit=[[-1]*m for _ in range(n+1)]
dx=[-1,0,1,0]
dy=[0,1,0,-1]
def bfs():
    global dq
    global visit
    x=y=0
    while dq:
        x,y=dq.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<n and 0<=ny<m:
                if board[nx][ny]==0 and visit[nx][ny]==-1:
                    board[nx][ny]=1
                    visit[nx][ny]=visit[x][y]+1
                    dq.append((nx,ny))
    return visit[x][y]

for i in range(n):
    arr=list(map(int,sys.stdin.readline().split()))
    board.append(arr)
for i in range(n):
    for j in range(m):
        if board[i][j]==1:
            dq.append((i,j))
            visit[i][j]=0

ans=-1
ans=bfs()
for i in range(n):
    for j in range(m):
        if board[i][j]==0:
            print(-1)
            exit(0)
print(ans)