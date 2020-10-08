import sys
def gcd(x,y):
    z=0
    while y!=0:
        z=x%y
        x=y
        y=z
    return x
if __name__=="__main__":
    a,b=map(int,sys.stdin.readline().split())
    ans=gcd(a,b)
    for i in range(ans):
        print(1,end='')

