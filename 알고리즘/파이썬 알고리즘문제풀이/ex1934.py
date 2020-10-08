import sys
def gcd(x,y):
    z=0
    while y!=0:
        z=x%y
        x=y
        y=z
    return x

def lcm(x,y):
    return (x*y)//gcd(x,y)

if __name__=="__main__":
    n=int(sys.stdin.readline().rstrip())
    for i in range(n):
        a,b=map(int,sys.stdin.readline().split())
        ans= lcm(a,b)
        print(ans)

