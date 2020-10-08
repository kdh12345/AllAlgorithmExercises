import sys
import bisect
n=int(sys.stdin.readline().rstrip())
people=set(map(int,sys.stdin.readline().split()))
m=int(sys.stdin.readline().rstrip())
num=list(map(int,sys.stdin.readline().split()))
for i in range(len(num)):
    if num[i] in people:
        print(1,end=' ')
    else:
        print(0,end=' ')
