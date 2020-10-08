import sys
word=sys.stdin.readline().rstrip()
n=int(sys.stdin.readline().rstrip())
cursor=len(word)
arr=list(word)
res=[]
for i in range(n):
    cmd=sys.stdin.readline().split()
    if cmd[0]=="L":
        if len(arr)>0:
            res.append(arr.pop())
        else:
            continue
    elif cmd[0]=="D":
        if len(res)>0:
            arr.append(res.pop())
        else:
            continue
    elif cmd[0]=="B":
        if len(arr)>0:
            arr.pop()
    elif cmd[0]=="P":
        arr.append(cmd[1])
word=''.join(arr+list(reversed(res)))
print(word)
    