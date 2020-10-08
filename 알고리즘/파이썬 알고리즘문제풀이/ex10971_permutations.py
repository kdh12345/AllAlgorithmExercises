import sys
from itertools import permutations
n=int(sys.stdin.readline().rstrip())
cost=[]
def calc_route(r):
    global n,cost
    result=0
    for i in range(len(r)-1):
        if cost[r[i]][r[i+1]]!=0:
            result+=cost[r[i]][r[i+1]]
        else:
            return -1
    if cost[r[-1]][r[0]]!=0:
        result+=cost[r[-1]][r[0]]
    else:
        return -1
    return result
for i in range(n):
    arr=list(map(int,sys.stdin.readline().split()))
    cost.append(arr)
ans=int(1e9)
candi=[i for i in range(n)]
for item in permutations(candi):
    res=calc_route(item)
    if res!=-1:
        ans=min(ans,res)
print(ans)