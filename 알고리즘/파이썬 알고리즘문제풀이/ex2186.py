import sys
import copy
n,m,k=map(int,sys.stdin.readline().split())
dx=[-1,1,0,0]
dy=[0,0,-1,1]
def dfs(x,y,now):
    if now==len(target):
        return 1
    if dist[x][y][now]!=-1:#이미 처리
        return dist[x][y][now]
    dist[x][y][now]=0
    for i in range(4):
        cur_x,cur_y=x,y
        for _ in range(k):
            nx=cur_x+dx[i]
            ny=cur_y+dy[i]
            if 0<=nx<n and 0<=ny<m:
                if maps[nx][ny]==target[now]:
                    dist[x][y][now]+=dfs(nx,ny,now+1)
            cur_x,cur_y=nx,ny
    return dist[x][y][now]

maps=[]
for i in range(n):
    word=sys.stdin.readline().strip()
    arr=list(word)
    maps.append(arr)
target=list(str(sys.stdin.readline().rstrip()))
start=[]
for i in range(n):
    for j in range(m):
        if maps[i][j]==target[0]:
            start.append([i,j])

dist=[[[-1]*len(target) for _ in range(m)] for _ in range(n)]
ans=0
for i in range(len(start)):
    sx,sy=start[i]
    ans+=dfs(sx,sy,1)
print(ans)