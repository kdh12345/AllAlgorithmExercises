import sys
word=sys.stdin.readline().strip()
alpha=[0]*26
for i in range(len(word)):
    alpha[ord(word[i])-97]+=1
for i in alpha:
    print(i,end=' ')