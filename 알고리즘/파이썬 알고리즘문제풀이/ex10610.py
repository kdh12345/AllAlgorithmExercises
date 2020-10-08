import sys
from itertools import permutations
n=sys.stdin.readline().rstrip()
n=sorted(n,reverse=True)
total=0
if '0' not in n:
    print(-1)
else:
    for i in n:
        total+=int(i)
    if total%3!=0:
        print(-1)
    else:
        print(''.join(n))

