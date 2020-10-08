import sys
n=int(sys.stdin.readline().rstrip())
ans=n//5+n//25+n//125
print(ans)