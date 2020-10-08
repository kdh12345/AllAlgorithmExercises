import sys
from collections import deque
t=int(sys.stdin.readline().rstrip())
def go(start,end):
    global visit
    cur=0
    dq=deque()
    dq.append([start,""])
    visit[start]=1
    while len(dq)!=0:
        num,res=dq.popleft()
        if num==end:
            return res
        cur=2*num
        if cur<10000 and visit[cur]==0:
            visit[cur]=1
            dq.append([cur,res+'D'])
        if cur>=10000 and visit[cur%10000]==0:
            cur=(2*num)%10000
            visit[cur]=1
            dq.append([cur,res+'D'])
        cur=num-1
        if cur<0 and visit[cur]==0:
            dq.append([9999,res+'S'])
            visit[9999]=1
        if cur>=0 and visit[cur]==0:
            visit[cur]=1
            dq.append([cur,res+'S'])
        cur=(num%1000)*10+num//1000
        if visit[cur]==0:
            visit[cur]=1
            dq.append([cur,res+'L'])
        cur=(num%10)*1000+num//10
        if visit[cur]==0:
            visit[cur]=1
            dq.append([cur,res+'R'])
    return

for i in range(t):
    visit = [0] * 10001
    a,b=map(int,sys.stdin.readline().split())
    answer=go(a,b)
    print(answer)