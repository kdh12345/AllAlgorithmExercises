import sys
n=int(sys.stdin.readline().rstrip())
q=[]
for i in range(n):
    cmd=sys.stdin.readline().split()
    if cmd[0]=="push_front":
        num=cmd[1]
        q.insert(0,num)
    if cmd[0]=='push_back':
        num=cmd[1]
        q.append(num)
    if cmd[0]=="pop_front":
        if len(q)==0:
            print(-1)
        else:
            print(q.pop(0))
    if cmd[0]=="pop_back":
        if len(q)==0:
            print(-1)
        else:
            print(q.pop(-1))
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