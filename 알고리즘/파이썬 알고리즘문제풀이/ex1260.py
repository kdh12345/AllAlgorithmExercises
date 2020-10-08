import sys
from collections import deque
def dfs(v,n):
    visit[v]=True
    print(v,end=' ')
    for i in range(1,n+1):
        if visit[i]==False and conn[v][i]==1:
            
            dfs(i,n)

def bfs(s,n):
    dq= deque()
    dq.append(s)
    visit[s]=True
    while len(dq)!=0:
        x=dq.popleft()
        print(x,end=' ')
        for i in range(1,n+1):
            if visit[i]==False and conn[x][i]==1:
                dq.append(i)
                visit[i]= True
if __name__ == "__main__":
    n,m,s=map(int,sys.stdin.readline().split())
    global visit
    visit=[False]*(n+1)
    global conn
    conn=[[0]*(n+1) for _ in range(n+1)]
    for i in range(m):
        a,b= map(int,sys.stdin.readline().split())
        conn[a][b]=1
        conn[b][a]=1
    dfs(s,n)
    print()
    visit=[False]*(n+1)
    bfs(s,n)
