import sys
n,k=map(int,sys.stdin.readline().split())
arr=[0]*(n+1)
for i in range(1,n+1):
    arr[i]=i
idx=0
print('<',end='')
while n>0:
    idx=(idx+k)%n # 원의 회전
    if idx==0:
        idx=n
    if n==1:
        print(arr[idx],end='')
    else:
        print(arr[idx],end='')
        print(', ',end='')
        arr.pop(idx)
        idx-=1
    n-=1
print('>',end='')
