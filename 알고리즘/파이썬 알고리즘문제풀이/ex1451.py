import sys
n,m=map(int,sys.stdin.readline().split())
maps=[[0]*101 for _ in range(102)]
def res(a,b,c,d):
    result=total[c][d]-total[c][b-1]-total[a-1][d]+total[a-1][b-1]
    return result
for i in range(1,n+1):
    arr=list(map(int,sys.stdin.readline().rstrip()))
    for j in range(1,m+1):
        maps[i][j]=arr[j-1]

total=[[0]*101 for _ in range(102)]
ans=0
for i in range(1,n+1):
   for j in range(1,m+1):
      total[i][j]=total[i-1][j]+total[i][j-1]-total[i-1][j-1]+maps[i][j]
ans=0
for i in range(1,m-1):
    for j in range(i+1,m):
        res1=res(1,1,n,i)
        res2=res(1,i+1,n,j)
        res3=res(1,j+1,n,m)
        if ans<res1*res2*res3:
            ans=res1*res2*res3
for i in range(1,n-1):
    for j in range(i+1,n):
        res1=res(1,1,i,m)
        res2=res(i+1,1,j,m)
        res3=res(j+1,1,n,m)
        if ans<res1*res2*res3:
            ans=res1*res2*res3

for i in range(1,n):
    for j in range(1,m):
        res1=res(1,1,n,j)
        res2=res(1,j+1,i,m)
        res3=res(i+1,j+1,n,m)
        if ans<res1*res2*res3:
            ans=res1*res2*res3
        res1=res(1,1,i,j)
        res2=res(i+1,1,n,j)
        res3=res(1,j+1,n,m)
        if ans<res1*res2*res3:
            ans=res1*res2*res3
        res1=res(1,1,i,m)
        res2=res(i+1,1,n,j)
        res3=res(i+1,j+1,n,m)
        if ans<res1*res2*res3:
            ans=res1*res2*res3
        res1=res(1,1,i,j)
        res2=res(1,j+1,i,m)
        res3=res(i+1,1,n,m)
        if ans<res1*res2*res3:
            ans=res1*res2*res3
print(ans)

