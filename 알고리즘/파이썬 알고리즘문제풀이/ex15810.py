import sys
def get_sum(minuto,v):
    total=0
    for item in v:
        total+=(minuto//item)
    return total
def binSearch(v,target):
    left=0
    right=1000000000000
    while left<right:
        mid=(left+right)//2
        if get_sum(mid,v)<target:
            left=mid+1
        else:
            right=mid
    return right
n,m=map(int,sys.stdin.readline().split())
arr=list(map(int,sys.stdin.readline().split()))
arr.sort()
ans=0
ans=binSearch(arr,m)
print(ans)
