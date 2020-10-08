import sys
n,m,k=map(int,sys.stdin.readline().split())
sum=n+m-k
candi1=sum//3
candi2=min(n//2,m)
ans=min(candi1,candi2)
print(ans)