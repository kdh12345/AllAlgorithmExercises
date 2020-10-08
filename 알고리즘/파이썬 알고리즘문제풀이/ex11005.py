import sys
n,b=map(int,sys.stdin.readline().split())
jinbub="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
ans=""
while n!=0:
    ans+=str(jinbub[n%b])
    n//=b
print(ans[::-1])

    