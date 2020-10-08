import sys
def chk(n):
    if n==1:
        return False
    for i in range(2,n+1):
        if i*i>n:
            break
        if n%i==0:
            return False
    return True
if __name__=='__main__':
    n=int(sys.stdin.readline().rstrip())
    arr=list(map(int,sys.stdin.readline().split()))
    cnt=0
    for i in arr:
        if chk(i)==True:
            cnt+=1
    print(cnt)