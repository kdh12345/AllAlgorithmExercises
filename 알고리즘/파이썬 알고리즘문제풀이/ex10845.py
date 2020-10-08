import sys
n=int(sys.stdin.readline().rstrip())
q=[]
for i in range(n):
    cmd=sys.stdin.readline().split()
    if cmd[0]=="push":
        num=cmd[1]
        q.append(num)
    if cmd[0]=="pop":
        if len(q)==0:
            print(-1)
        else:
            print(q[0])
            q.remove(q[0])
    if cmd[0]=="empty":
        if len(q)==0:
            print(1)
        else:
            print(0)
    if cmd[0]=="size":
        print(len(q))
    if cmd[0]=="front":
        if len(q)==0:
            print(-1)
        else:
            print(q[0])
    if cmd[0]=="back":
        if len(q)==0:
            print(-1)
        else:
            print(q[-1])