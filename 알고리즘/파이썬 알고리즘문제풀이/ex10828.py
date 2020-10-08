import sys
n=int(sys.stdin.readline().rstrip())
arr=[]
for i in range(n):
    cmd=sys.stdin.readline().split()
    if cmd[0]=="push":
        num=cmd[1]
        arr.append(num)
    if cmd[0]=="pop":
        if len(arr)==0:
            print(-1)
        else:
            print(arr[-1])
            arr.pop()
    if cmd[0]=="empty":
        if len(arr)==0:
            print(1)
        else:
            print(0)
    if cmd[0]=="size":
        print(len(arr))
    if cmd[0]=="top":
        if len(arr)==0:
            print(-1)
        else:
            print(arr[-1])