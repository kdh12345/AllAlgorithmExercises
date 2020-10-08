import sys
num=int(sys.stdin.readline().rstrip())
for i in range(2,num+1):
    while num%i==0:
        print(i)
        num//=i
if num>1:
    print(num)