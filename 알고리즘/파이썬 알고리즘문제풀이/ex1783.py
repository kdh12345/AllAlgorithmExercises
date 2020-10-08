import sys
#직접 그림을 그리면서 가능한 영역을 구분하는 문제
n,m=map(int,sys.stdin.readline().split())
if n==1:
    print(1)
elif n==2:
    ans=min(4,(m+1)//2)
    print(ans)
else:
    if m<7:
        ans=min(4,m)
        print(ans)
    else:
        ans=m-2
        print(ans)
