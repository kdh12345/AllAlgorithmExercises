#include <iostream>
#include <queue>
#include<string.h>
using namespace std;
int map[1001][1001] = { 0, };
int visit[1001][1001] = { 0, };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int m, n;
queue<pair<int, int>> q;
int bfs() {
	int nowX, nowY, nextX, nextY;
	while (!q.empty()) {
		nowX = q.front().first;
		nowY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			nextX = nowX + dx[i];
			nextY = nowY + dy[i];
			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m) {
				if (map[nextX][nextY] == 0 && visit[nextX][nextY] == -1) {
					q.push({ nextX,nextY });
					visit[nextX][nextY] = visit[nowX][nowY] + 1;
					map[nextX][nextY] = 1;
				}
			}
		}
	}
	return visit[nowX][nowY];
}
int main(void) {
	memset(visit, -1, sizeof(visit));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			map[i][j] = num;
			if (num == 1) {
				q.push({ i,j });
				visit[i][j] = 0;
			}
		}
	}
	int day = bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	cout << day << '\n';
	return 0;
}