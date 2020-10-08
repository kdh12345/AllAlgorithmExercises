import sys
a,b=map(int,sys.stdin.readline().split())
arr=[]
arr=list(map(int,sys.stdin.readline().split()))
arr.sort()
print(arr[b-1])