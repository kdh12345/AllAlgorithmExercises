import sys
import math
n=int(sys.stdin.readline().rstrip())
d=[]
#비트마스크를 이용하여 visit검사를 log(n)에 해결한다
def get_distance(k,v):
    return math.sqrt(pow(k[0] - v[0], 2) + pow(k[1] - v[1], 2))
def tsp(now,cur,v):
    if cur==n:
        return get_distance(d[now],d[1])
    if dp[now][v]!=0:
        return dp[now][v]

    result=1e9
    visit[now]=1
    for i in range(1,n+1):
        if visit[i]!=0:
            continue
        result=min(result,get_distance(d[now],d[i])+tsp(i,cur+1,v|(1<<(i-1))))
    visit[now]=0
    dp[now][v]=result
    return result
d.append((-1,-1))
for i in range(n):
    a,b=map(int,sys.stdin.readline().split())
    d.append((a,b))
dp=[[0]*(1<<17) for _ in range(18)]
visit=[0]*17
ans=tsp(1,1,1)
print("%.10f" %ans)
