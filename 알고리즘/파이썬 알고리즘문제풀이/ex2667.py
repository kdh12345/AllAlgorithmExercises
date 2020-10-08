import sys
n=int(sys.stdin.readline().rstrip())
board=[[0]*n for _ in range(n+1)]
visit=[[0]*n for _ in range(n+1)]
dx=[-1,0,1,0]
dy=[0,1,0,-1]

def dfs(x,y):
    global cnt
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx and nx<n and 0<=ny and ny<n:
            if board[nx][ny]==1 and visit[nx][ny]==0:
                visit[nx][ny]=1
                cnt+=1
                dfs(nx,ny)
for i in range(n):
    arr=sys.stdin.readline().rstrip()
    for j,v in enumerate(arr):
        board[i][j]=int(v)
v=[]
cnt=0
for i in range(n):
    for j in range(n):
        if visit[i][j]==0 and board[i][j]==1:
            visit[i][j]=1
            cnt += 1
            dfs(i,j)
            v.append(cnt)
            cnt=0
v.sort()
print(len(v))
for i in v:
    print(i)
