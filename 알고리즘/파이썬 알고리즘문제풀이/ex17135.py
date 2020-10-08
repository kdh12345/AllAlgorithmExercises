from itertools import combinations
from copy import deepcopy
import sys
n,m,d=map(int,sys.stdin.readline().split())
enemy_pos=set()
for y in range(n):#행
    arr=list(map(int,sys.stdin.readline().split()))
    for x in range(m):#열
        if arr[x]==1:#적
            enemy_pos.add((y,x))


board=[[0]*m for _ in range(n)]
archor_pos=[(n,i) for i in range(m)]

candi=combinations(archor_pos,3)
#거리계산
def get_dist(board,candi,d):
    possible_attack_area=[]
    for pos in candi:
        copies=[]
        for y in range(len(board)):
            for x in range(len(board[0])):
                if abs(pos[0]-y)+abs(pos[1]-x)<=d:
                    copies.append((abs(pos[0]-y)+abs(pos[1]-x),y,x))
        possible_attack_area.append(copies)
    return possible_attack_area
# 적군의 움직임 밑으로 1칸
def go(enemy_pos,n):
    return set([(y+1,x) for y,x in enemy_pos if y+1<n])

def find_nearest_enemy(archor,enemy_pos):
    archor.sort(key=lambda x: (x[0],x[2]))#가장 왼쪽 부터
    for dist,y,x in archor:
        if (y,x) in enemy_pos:
            return (y,x)
    return None

max_val=0
for archors in candi:
    arc=get_dist(board,archors,d)
    kills=0
    #초기화
    copy_enemy_maps=deepcopy(enemy_pos)
    while enemy_pos:
        tmp=set()
        for arc_map in arc:
            kill=find_nearest_enemy(arc_map,enemy_pos)
            if kill is not None:
                tmp.add(kill)
        kills+=len(tmp)
        #공격한 좌표는 남은 적군의 위치에서 삭제
        enemy_pos-=tmp
        #적의 움직임
        enemy_pos=go(enemy_pos,n)
    enemy_pos=copy_enemy_maps
    if max_val<kills:
        max_val=kills
print(max_val)

