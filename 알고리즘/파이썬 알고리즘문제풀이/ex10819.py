import sys
from itertools import permutations
def calc(candis):
    answer=-100
    for now in candis:
        arr = list(now)
        diff = 0
        for i in range(1, len(arr)):
            diff += abs(arr[i] - arr[i - 1])
        if answer<diff:
            answer=diff
    return answer
t=int(sys.stdin.readline().rstrip())
arr=list(map(int,sys.stdin.readline().split()))
candi=list(permutations(arr,t))
ans=-100
ans=max(ans,calc(candi))
print(ans)