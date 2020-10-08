import sys
from itertools import combinations
def gcd(x,y):
    z=0
    while y!=0:
        z=x%y
        x=y
        y=z
    return x
t=int(sys.stdin.readline().rstrip())
for i in range(t):
    arr=list(map(int,sys.stdin.readline().split()))
    arr=arr[1:]
    com=list(combinations(arr,2))
    total=0
    for i in range(len(com)):
        ans=gcd(com[i][0],com[i][1])
        total+=ans
    print(total)