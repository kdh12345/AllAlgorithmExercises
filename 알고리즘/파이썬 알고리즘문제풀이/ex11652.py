import sys
n=int(sys.stdin.readline().rstrip())
arr={}
for i in range(n):
    num=int(sys.stdin.readline().rstrip())
    if num in arr.keys():
        arr[num]+=1
    if num not in arr.keys():
        arr[num]=1
max_val=max(arr.values())
ans=[]
for k,v in arr.items():
    if arr[k]== max_val:
        ans.append(k)
ans.sort()
print(ans[0])