import sys
sys.setrecursionlimit(10000)
from collections import deque
n=int(sys.stdin.readline().rstrip())
maps=[]
visit=[[0]*n for _ in range(n+1)]
for i in range(n):
    arr=list(map(int,sys.stdin.readline().split()))
    maps.append(arr)
dx=[-1,0,1,0]
dy=[0,1,0,-1]

def dfs(x,y,cnt):
    global visit
    global maps
    visit[x][y]=1
    maps[x][y]=cnt
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx<n and 0<=ny<n:
            if maps[nx][ny]>=1 and visit[nx][ny]==0:
                dfs(nx,ny,cnt)


def bfs(cnt):
    global visit
    global maps
    q=deque()
    for i in range(n):
        for j in range(n):
            if maps[i][j]==cnt:
                visit[i][j]=1
                q.append((i,j))
    res=0
    while q:
        siz=len(q)
        for k in range(siz):
            x,y=q.popleft()
            for i in range(4):
                nx=x+dx[i]
                ny=y+dy[i]
                if 0<=nx<n and 0<=ny<n:
                    if maps[nx][ny]>=1 and maps[nx][ny]!=cnt:
                        return res
                    elif maps[nx][ny]==0 and visit[nx][ny]==0:
                        visit[nx][ny]=1
                        q.append((nx,ny))
        res+=1
    return res


count = 1
for i in range(n):
    for j in range(n):
        if maps[i][j] == 1 and visit[i][j] == 0:
            dfs(i, j, count)
            count += 1
min_val = int(1e9)
for i in range(1, count):
    visit = [[0] * n for _ in range(n + 1)]
    min_val = min(min_val, bfs(i))
print(min_val)

