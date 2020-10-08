import sys
sys.setrecursionlimit(100001)
t=int(sys.stdin.readline().rstrip())
def dfs(v,cur,cnt):
    if visit[cur]:
        if first[cur]!=v:
            return 0
        else:#사이클x
            return cnt-visit[cur]
    visit[cur]=cnt
    first[cur]=v
    return dfs(v,arr[cur],cnt+1)

for i in range(t):
    n=int(sys.stdin.readline())
    arr=[0]+list(map(int,sys.stdin.readline().split()))
    visit=[0]*100001
    first=[0]*100001
    ans=0
    for i in range(1,n+1):
        if visit[i]==0:
            ans+=dfs(i,i,1)
    ans=n-ans
    print(ans)