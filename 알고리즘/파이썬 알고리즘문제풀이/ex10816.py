from collections import Counter
import sys
n=int(sys.stdin.readline().rstrip())
data=list(map(int,sys.stdin.readline().split()))
m=int(sys.stdin.readline().rstrip())
arr=list(map(int,sys.stdin.readline().split()))
dic=dict(Counter(data).most_common())
print(type(dic))
for i in arr:
    if i in dic.keys():
        print(dic[i],end=' ')
    elif i not in dic.keys():
        print(0,end=' ')
