import sys
sys.setrecursionlimit(10000)
dx=[-1,-1,0,1,1,1,0,-1]
dy=[0,1,1,1,0,-1,-1,-1]
def dfs(x,y):
    for i in range(8):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx and nx<n and 0<=ny and ny<m:
            if visit[nx][ny]==0 and v[nx][ny]==1:
                visit[nx][ny]=1
                dfs(nx,ny)
while True:
    m, n = map(int, sys.stdin.readline().split())
    if m==0 and n==0:
        break
    v=[]
    for i in range(n):
        arr=list(map(int,sys.stdin.readline().split()))
        v.append(arr)
    visit=[[0]*m for _ in range(n+1)]
    cnt=0
    for i in range(n):
        for j in range(m):
            if v[i][j]==1 and visit[i][j]==0:
                dfs(i,j)
                cnt+=1
    print(cnt)

