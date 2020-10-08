import sys
ans=0
pr=input()
arr=[]
for j in range(len(pr)):
    if pr[j]=='(':
        arr.append('(')
    if pr[j]==')':
        if pr[j-1]=='(':
            arr.pop()
            ans+=len(arr)
        else:
            arr.pop()
            ans+=1

print(ans)