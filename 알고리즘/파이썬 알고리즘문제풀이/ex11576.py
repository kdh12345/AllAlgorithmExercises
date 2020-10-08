import sys
a,b=map(int,sys.stdin.readline().split())
m=input()
arr=list(map(int,sys.stdin.readline().split()))
total=0
mul=0
for i in range(len(arr)):#a진법->10진법으로 변환
    total+=(arr.pop()*(a**i))
res=[]
while total!=0:#10->b진법
    res.append(total%b)
    total//=b
while res:
    print(res.pop(),end=' ')
    
    

    