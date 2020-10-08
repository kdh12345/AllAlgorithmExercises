import sys
from collections import deque
def bfs():
    global n,k
    dq=deque()
    dq.append(n)
    visit[n]=1
    now=0
    while len(dq)!=0:
        now=dq.popleft()
        if now==k:
            return visit[now]-1
        if now-1>=0 and visit[now-1]==0:
            visit[now-1]=visit[now]+1
            dq.append(now-1)
        if now+1<=100000 and visit[now+1]==0:
            visit[now+1]=visit[now]+1
            dq.append(now+1)
        if 2*now<=100000 and visit[2*now]==0:
            visit[2*now]=visit[now]+1
            dq.append(2*now)
    return visit[now]-1


n,k=map(int,sys.stdin.readline().split())
visit=[0]*100001
answer=bfs()
print(answer)