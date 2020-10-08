import sys
from collections import deque
word=sys.stdin.readline().rstrip()
arr=[]
for i in range(len(word)):
    tmp=word[len(word)-(i+1):]
    arr.append(tmp)
arr.sort()
for i in arr:
    print(i)