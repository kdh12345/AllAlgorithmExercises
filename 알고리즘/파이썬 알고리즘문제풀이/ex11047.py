import sys
n,k=map(int,sys.stdin.readline().split())
arr=[]
for i in range(n):
    num=int(sys.stdin.readline())
    arr.append(num)
arr.reverse()
ans=0
for item in arr:
    if k>=item:
        ans+=(k//item)
        k%=item
    if k==0:
        break
print(ans)