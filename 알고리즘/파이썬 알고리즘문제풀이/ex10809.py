import sys
word=sys.stdin.readline().rstrip()
alpha=[-1]*26
for i in range(len(word)):
    idx=word.find(word[i])
    alpha[ord(word[i])-97]=idx
for i in alpha:
    print(i,end=' ')