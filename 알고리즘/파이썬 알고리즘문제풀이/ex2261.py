import sys
import math
n=int(sys.stdin.readline().rstrip())
arr=[]
for i in range(n):
    a,b=map(int,sys.stdin.readline().split())
    arr.append((a,b))
arr=sorted(arr,key=lambda x:x[0])
arr=sorted(arr,key=lambda x:x[1])
min_val=int(1e9)
for i in range(len(arr)-1):
    diff_x=abs(arr[i+1][0]-arr[i][0])
    diff_y=abs(arr[i+1][1]-arr[i][1])
    diff=diff_x+diff_y
    if min_val>diff:
        min_val=diff
print(min_val)