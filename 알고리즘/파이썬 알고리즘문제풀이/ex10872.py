import sys
n=int(sys.stdin.readline().rstrip())
if n==0:
    print(1)
else:
    mul=n-1
    ans=n
    for i in range(n-1,0,-1):
        ans*=mul
        mul-=1
    print(ans)