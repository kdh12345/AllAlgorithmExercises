import sys
n,m=map(int,sys.stdin.readline().split())
arr=list(map(int,sys.stdin.readline().split()))
arr.sort()
left=1
right=arr[-1]
while left<=right:
    mid=(left+right)//2
    sum=0
    for i in arr:
        if i>mid:
            sum+=(i-mid)
    if sum>=m:
        left=mid+1
    elif sum<m:
        right=mid-1
print(right)