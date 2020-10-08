import sys
sys.setrecursionlimit(100000)
t=int(sys.stdin.readline().rstrip())


def dfs(v):
    visit[v]=1
    next=arr[v]
    if visit[next]==0:
        dfs(next)


for _ in range(t):
    n = int(sys.stdin.readline())
    arr = [0]+list(map(int,sys.stdin.readline().split()))
    visit=[0]*(n+1)
    cnt=0
    for i in range(1,n+1):
        if visit[i]==0:
            dfs(i)
            cnt+=1
    print(cnt)