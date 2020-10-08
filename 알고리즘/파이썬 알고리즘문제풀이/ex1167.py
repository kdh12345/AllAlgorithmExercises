import sys
sys.setrecursionlimit(10**9)
v=int(sys.stdin.readline().rstrip())

matrix=[[] for _ in range(v+1)]
for _ in range(v):
    path=list(map(int,sys.stdin.readline().split()))
    path_len=len(path)
    for i in range(1,path_len//2):
        matrix[path[0]].append([path[2*i-1],path[2*i]])

result1=[0]*(v+1)

def dfs(s,matrix,res):
    for e,d in matrix[s]:
        if res[e]==0:
            res[e]=res[s]+d
            dfs(e,matrix,res)
dfs(1,matrix,result1) #최장노드를 탐색
result1[1]=0

max_val=0
idx=0#최장경로 노드

for i in range(len(result1)):
    if max_val<result1[i]:
        max_val=result1[i]
        idx=i

result2=[0]*(v+1)
dfs(idx,matrix,result2)#최장노드를 기반으로 지름 측정
result2[idx]=0
ans=max(result2)
print(ans)
