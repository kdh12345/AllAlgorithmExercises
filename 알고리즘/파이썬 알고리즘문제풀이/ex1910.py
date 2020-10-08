import sys
n=int(sys.stdin.readline().rstrip())
meeting=[]
for i in range(n):
    s,e=map(int,sys.stdin.readline().split())
    meeting.append((s,e))
meeting=sorted(meeting,key=lambda x:x[0])
meeting=sorted(meeting,key=lambda x:x[1])
start=meeting[0][1]
times=1
for i in range(1,len(meeting)):
    if start<=meeting[i][0]:
        start=meeting[i][1]
        times+=1
print(times)


