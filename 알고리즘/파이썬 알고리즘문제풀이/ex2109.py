import sys
import heapq
n=int(sys.stdin.readline().rstrip())
h=[]
arr=[]
for i in range(n):
    p,d=map(int,sys.stdin.readline().split())
    arr.append((d,p))
arr=sorted(arr)
total=0
prev=0
day=0
for k,v in arr:
    total+=v
    heapq.heappush(h,v)
    if len(h)>k:
        total-=h[0]
        heapq.heappop(h)
print(total)

    