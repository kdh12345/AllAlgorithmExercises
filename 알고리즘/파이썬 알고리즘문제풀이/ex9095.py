import sys
t=int(sys.stdin.readline().rstrip())
dp=[0]*12
dp[0]=1
dp[1]=1
dp[2]=2
for i in range(t):
    num=int(sys.stdin.readline().rstrip())
    for j in range(3,num+1):
        dp[j]=dp[j-1]+dp[j-2]+dp[j-3]
    print(dp[num])

