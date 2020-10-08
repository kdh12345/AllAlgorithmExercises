import sys
from collections import deque
dx=[-1,0,1,0]
dy=[0,1,0,-1]
def solve(v):
    dq=deque()
    dq.append(v)
    visit[v]=0
    while len(dq)!=0:
        now=dq.popleft()
        if now==123456789:
            return visit[now]
        number=str(now)
        zero=number.find('9')
        x=zero//3
        y=zero%3
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<3 and 0<=ny<3:
                nZero=nx*3+ny
                arr=list(number)
                arr[zero],arr[nZero]=arr[nZero],arr[zero]
                nextNum=int(''.join(arr))

                if not visit.get(nextNum):
                    visit[nextNum]=visit[now]+1
                    dq.append(nextNum)
    return -1

maps=''
visit={}
for i in range(3):
    arr=sys.stdin.readline().strip()
    arr=arr.replace(' ','')
    maps+=arr
maps=maps.replace('0','9')
maps=int(maps)
answer=solve(maps)
print(answer)