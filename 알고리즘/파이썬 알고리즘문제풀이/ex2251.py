import sys
from collections import deque
import math
def bfs(a,b,c):
    dq=deque()
    dq.append([0,0,c])
    res=[]
    while len(dq)!=0:
        na,nb,nc=dq.popleft()
        if visit[na][nb]==1:
            continue
        visit[na][nb]=1
        if na==0:
          res.append(nc)
        #a->b
        if na+nb>b:
            dq.append([na+nb-b,b,nc])
        else:
            dq.append([0,na+nb,nc])
        #a->c
        if na+nc>c:
            dq.append([na+nc-c,nb,c])
        else:
            dq.append([0,nb,na+nc])
        #b->a
        if nb+na>a:
            dq.append([a,nb+na-a,nc])
        else:
            dq.append([nb+na,0,nc])
        #b->c
        if nb+nc>c:
            dq.append([na,nb+nc-c,c])
        else:
            dq.append([na,0,nb+nc])
        #c->a
        if nc+na>a:
            dq.append([a,nb,nc+na-a])
        else:
            dq.append([na+nc,nb,0])
        #c->b
        if nc+nb>b:
            dq.append([na,b,nc+nb-b])
        else:
            dq.append([na,nc+nb,0])
    return res

visit=[[0]*201 for _ in range(202)]
a,b,c=map(int,sys.stdin.readline().split())
ans=bfs(a,b,c)
ans.sort()
for item in ans:
    print(item,end=' ')
