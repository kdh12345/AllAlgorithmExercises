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
    s,e=map(int,sys.stdin.readline().split())
    for i in range(s,e+1):
        if chk(i)==True:
            print(i)
    