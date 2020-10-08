import sys

sys.setrecursionlimit(100000)


def dfs(d, group, arr, visit):
    visit[d] = group
    for i in arr[d]:
        if visit[i] == 0:
            if dfs(i, -group, arr, visit) is False:
                return False
        elif visit[i] == visit[d]:
            return False
    return True


t = int(sys.stdin.readline().rstrip())
for i in range(t):
    v, e = map(int, sys.stdin.readline().split())
    conn = [[] for _ in range(v + 1)]
    visit = [0] * (v + 1)
    for j in range(e):
        a, b = map(int, sys.stdin.readline().split())
        conn[a].append(b)
        conn[b].append(a)
    flag = True
    for k in range(1, v + 1):
        if visit[k] == 0:
            if dfs(k, 1, conn, visit) is False:
                flag = False
                break
    if flag == True:
        print("YES")
    elif flag == False:
        print("NO")


