import sys
from collections import deque
import copy
t=int(sys.stdin.readline().rstrip())
def chk(num):
    i=2
    while i*i<=num:
        if num%i==0:
            return False
        i+=1
    return True

"""def go(start,end):
    if start==end:
        return 0
    s=int(start)
    dq=deque()
    dq.append(s)
    now=0
    visit[s]=1
    while len(dq)!=0:
        now=dq.popleft()
        if now==int(end):
            return visit[now]-1
        if now+1<10000 and visit[now+1]==0:
            if chk(now+1,end)==True:
                print(now+1)
                visit[now+1]=visit[now]+1
                dq.append(now+1)
            else:
                dq.append(now+1)
    return 0

def init_prime(s,e):
    global primes
    for i in range(s,e+1):
        primes[i]=i
    for i in range(s,e+1):
        if primes[i]==0:
            continue
        for j in range(2*i,e+1,i):
            primes[j]=0

primes=[0]*10000
visit=[0]*10000
for i in range(t):
    a,b=map(str,sys.stdin.readline().split())
    tmp1=int(a)
    tmp2=int(b)
    answer=0
    if tmp1<tmp2:
        init_prime(tmp1,tmp2)
        answer = go(a, b)
    elif tmp1>tmp2:
        init_prime(tmp2,tmp1)
        answer = go(b, a)
    print(answer)"""
def go(s,e):
    if s==e:
        return 0
    visit = [0] * 10000
    dq=deque([[list(str(s)),0]])
    visit[s]=1
    while len(dq)!=0:
        now,cnt=dq.popleft()
        if int("".join(map(str,now)))==e:
            return cnt
        else:
            for i in range(4):
                for j in range(10):
                    if now[i]==str(j):#자리의 숫자가 같다
                        continue
                    else:#자리 숫자가 다르다
                        tmp=copy.deepcopy(now)
                        tmp[i]=str(j)
                        tmp_val=int("".join(map(str,tmp)))
                        if visit[tmp_val]==0 and 1000<=tmp_val and chk(tmp_val)==True:
                            visit[tmp_val]=1
                            dq.append([tmp,cnt+1])
    return 0


for i in range(t):
    a,b=map(int,sys.stdin.readline().split())
    answer=go(a,b)
    print(answer)