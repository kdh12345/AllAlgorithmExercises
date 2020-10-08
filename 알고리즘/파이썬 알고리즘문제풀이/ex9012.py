import sys
n=int(sys.stdin.readline().rstrip())
for i in range(n):
    pr=input()
    arr=[]
    opens=0
    closes=0
    for j in pr:
        if j=='(':
            arr.append('(')
            opens+=1
        if j==')':
            closes+=1
            if len(arr)>0:
                arr.pop()
    if len(arr)==0 and opens==closes:
        print("YES")
    else:
        print("NO")