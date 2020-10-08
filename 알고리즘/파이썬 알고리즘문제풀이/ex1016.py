import sys
import math
Min, Max = map(int, sys.stdin.readline().rstrip().split())
square=4
ans=Max-Min+1
i=2
chk=[False for _ in range(Max-Min+2)]#Max-Min+2만큼 False로 초기화한 리스트
while i**2<=Max:
    start=Min//(i*i)
    if start*(i*i)!=Min:
        start+=1
    while start*(i*i)<= Max:
        if chk[start*(i*i)-Min]==False:
            chk[start*(i*i)-Min]= True
            ans-=1
        start+=1
    i+=1
print(ans)