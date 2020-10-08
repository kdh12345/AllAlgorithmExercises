import sys
n=int(sys.stdin.readline().rstrip())
visit=[0]*16
cost=[]
ans=int(1e9)
def dfs(start,row,cnt,sum):
    global ans
    if start==row and cnt==n:
        ans=min(ans,sum)
        return
    for col in range(n):
        if cost[row][col]>0 and visit[row]==0:
            sum+=cost[row][col]
            visit[row]=1
            if ans>=sum:
                dfs(start,col,cnt+1,sum)
            sum-=cost[row][col]
            visit[row]=0

for i in range(n):
    arr=list(map(int,sys.stdin.readline().split()))
    cost.append(arr)
for row in range(n):
    dfs(row,row,0,0)
print(ans)

