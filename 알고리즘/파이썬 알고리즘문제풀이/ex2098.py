import sys
n=int(sys.stdin.readline().rstrip())
cost=[]
#비트마스크를 이용하여 visit검사를 log(n)에 해결한다
def tsp(cur,visited):
    result=0
    answer=dp[cur][visited]
    if answer!=0:##이미 계산한적이 있다
        return answer
    if visited==(1<<n)-1:
        if cost[cur][0]!=0:
            return cost[cur][0]
        return int(1e9)

    answer=int(1e9)
    for i in range(n):
        if (visited&1<<i) or (cost[cur][i]==0):
            continue
        result=tsp(i,(visited|1<<i))+cost[cur][i]
        if answer>result:
            answer=result
    dp[cur][visited]=answer
    return answer

for i in range(n):
    arr=list(map(int,sys.stdin.readline().split()))
    cost.append(arr)
dp=[[0]*(1<<17) for _ in range(18)]
ans=tsp(0,1)
print(ans)
