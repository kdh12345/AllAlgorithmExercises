import sys
word=sys.stdin.readline().split()
n=word[0]
b=int(word[1])
jinbub="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
ans=0
for i,v in enumerate(n[::-1]):
    ans+=jinbub.find(v)*(b**i)
print(ans)

       