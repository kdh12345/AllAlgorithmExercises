import sys

prime=[0]*1000000
pn=0
check=[False]*1000001
for i in range(2,1000001):
    if check[i]==False:
        prime[pn]=i
        pn+=1
        for j in range(i+i,1000001,i):
            check[j]=True

while True:
    n=int(sys.stdin.readline().rstrip())
    if n==0:
        break
    for i in range(1,pn):
        if check[n-prime[i]]==False:
            print(n,"=",prime[i],"+",n-prime[i])
            break