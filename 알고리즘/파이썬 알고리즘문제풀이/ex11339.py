import sys
n=int(sys.stdin.readline().rstrip())
arr=list(map(int,sys.stdin.readline().split()))
arr.sort()
total=0
tmp=0
res=[]
"""for i in range(len(arr)):
    total=0
    for j in range(i+1):
        total+=arr[j]
    res.append(total)
ans=0
for item in res:
    ans+=item
print(ans)"""
for i in range(len(arr)):
    total+=(tmp+arr[i])
    tmp+=arr[i]
print(total)