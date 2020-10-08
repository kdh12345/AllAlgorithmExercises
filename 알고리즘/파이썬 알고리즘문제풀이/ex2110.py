import sys
import itertools
n,c=map(int,sys.stdin.readline().split())
arr=[]
for i in range(n):
    num=int(sys.stdin.readline())
    arr.append(num)
arr.sort()
left=1
right=arr[-1]-arr[0]
cnt=0
diff=0
while left<=right:
    cnt=1
    mid=(left+right)//2
    s=arr[0]
    for i in range(1,len(arr)):
        diff=arr[i]-s
        if mid<=diff:
            cnt+=1
            s=arr[i]
    if cnt>=c:
        left=mid+1
    elif cnt<c:
        right=mid-1
print(right)