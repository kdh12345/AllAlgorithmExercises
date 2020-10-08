import sys
k,n=map(int,sys.stdin.readline().split())
arr=[]
for i in range(k):
    num=int(sys.stdin.readline())
    arr.append(num)
arr.sort()
left=1
right=arr[-1]
while left<=right:
    mid=(left+right)//2
    sum=0
    for i in arr:
        sum+=i//mid
    if sum>=n:
        left=mid+1
    elif sum<n:
        right=mid-1

print(right)