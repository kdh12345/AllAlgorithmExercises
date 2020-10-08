import sys
n,k=map(int,sys.stdin.readline().split())
cnt2=0
cnt5=0
i=2
while i<=n:
    cnt2+=n//i
    i*=2
i=2
while i<=(n-k):
    cnt2-=(n-k)//i
    i*=2
i=2
while i<=k:
    cnt2-=k//i
    i*=2
i=5
while i<=n:
    cnt5+=n//i
    i*=5
i=5
while i<=(n-k):
    cnt5-=(n-k)//i
    i*=5
i=5
while i<=k:
    cnt5-=k//i
    i*=5
if cnt5>=cnt2:
    print(cnt2)
else:
    print(cnt5)
