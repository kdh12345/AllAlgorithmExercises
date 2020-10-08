import sys
import math
sys.setrecursionlimit(100000)
a,p=map(int,sys.stdin.readline().split())
chk=[0]*300000
idx=0
arr=[]
arr.append(a)
while True:
    if chk[a]>1:
        chk[a]+=1
        break
    chk[a]+=1
    tmp=a
    res=0
    while tmp!=0:
        res+=pow(tmp%10,p)
        tmp//=10
    arr.append(res)
    a=res
ans=0
for i in range(len(arr)):
    if chk[arr[i]]>1:
        break
    ans+=1
print(ans)