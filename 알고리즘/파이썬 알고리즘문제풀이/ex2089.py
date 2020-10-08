import sys
num= int(sys.stdin.readline().rstrip())
base=1
arr=[]
if num==0:
    print(0)
else:
    while num!=0:
        if num%2:
            arr.append(1)
            num-=base
        else:
            arr.append(0)
        base*=(-1)
        num//=2
for i in reversed(range(len(arr))):
    print(arr[i],end='')