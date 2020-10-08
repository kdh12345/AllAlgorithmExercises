import sys
n=int(sys.stdin.readline().rstrip())
t=int(sys.stdin.readline().rstrip())
arr=list(map(int,sys.stdin.readline().split()))
chk=[0]*200000
for item in arr:
    chk[item]=1
ans=abs(100-n)
def go(now):
    global ans
    for i in range(10):
        if chk[i]==0:
            tmp=now+str(i)
            cmp=abs(int(tmp)-n)+len(tmp)
            if ans>cmp:
                ans=cmp
            if len(tmp)<6:
                go(tmp)
go("")
print(ans)