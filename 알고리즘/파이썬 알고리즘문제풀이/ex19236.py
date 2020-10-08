import copy
import sys
arr=[[None]*4 for _ in range(4)]

for i in range(4):
    data=list(map(int,sys.stdin.readline().split()))
    # 매 줄마다 4마리의 물고기를 하나씩 확인
    for j in range(4):
        arr[i][j]=[data[j*2],data[j*2+1]-1]

dx=[-1,-1,0,1,1,1,0,-1]
dy=[0,-1,-1,-1,0,1,1,1]
#반시계 45도 왼쪽 회전

def turn_left(dir):
    dir=(dir+1)%8
    return dir

result=0

def find_fish(arr,idx):
    for i in range(4):
        for j in range(4):
            if arr[i][j][0]==idx:
                return (i,j)
    return None

#모든 물고기 회전+이동
def move_all_fish(arr,now_x,now_y):
    for i in range(1,17):
        pos=find_fish(arr,i)
        if pos!=None:
            x,y=pos[0],pos[1]
            dir=arr[x][y][1]
            for j in range(8):
                nx=x+dx[dir]
                ny=y+dy[dir]
                if 0<=nx and nx<4 and 0<=ny and ny<4:
                    if not(nx==now_x and ny==now_y):
                        arr[x][y][1]=dir
                        arr[x][y],arr[nx][ny]=arr[nx][ny],arr[x][y]
                        break
                dir=turn_left(dir)

#상어 현재 위치에서 먹을 수 있는 물고기 위치
def get_possible_pos(arr,now_x,now_y):
    pos=[]
    dir=arr[now_x][now_y][1]

    for i in range(4):
        now_x+=dx[dir]
        now_y+=dy[dir]
        if 0<=now_x and now_x<4 and 0<=now_y and now_y<4:
            if arr[now_x][now_y][0]!=-1:
                pos.append((now_x,now_y))
    return pos

def dfs(arr,now_x,now_y,total):
    global result
    arr=copy.deepcopy(arr)

    total+=arr[now_x][now_y][0]
    arr[now_x][now_y][0]=-1#먹은 물고기 표시

    move_all_fish(arr,now_x,now_y)

    pos=get_possible_pos(arr,now_x,now_y)
    if len(pos)==0:
        if result<total:
            result=total
            return
    for next_x,next_y in pos:
        dfs(arr,next_x,next_y,total)


dfs(arr,0,0,0)
print(result)
