#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int map[9][9];
int visit[9][9];
int visit2[9][9];
int n, m;
queue<pair<int, int>> q;
void bfs() {
	int nowX, nowY, nextX, nextY;
	int wall = 0;
	while (!q.empty()) {
		nowX = q.front().first;
		nowY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nextX = nowX + dx[i];
			nextY = nowY + dy[i];
			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m) {
				if (map[nextX][nextY] == 0 && visit[nextX][nextY] == 0) {
					visit[nextX][nextY] = 1;
					map[nextX][nextY] = 1;
					wall++;
					if (wall == 3) {
						return;
					}
				}
			}
		}
	}
}
void spread() {
	for (int x = 1; x < n; x++) {
		for (int y = 1; y < m; y++) {
			if (map[x][y] == 2) {
				if (map[x - 1][y] == 0) {
					map[x - 1][y] = 2;
				}
				if (map[x][y + 1] == 0) {
					map[x][y + 1] = 2;
				}
				if (map[x + 1][y] == 0) {
					map[x + 1][y] = 2;
				}
				if (map[x][y - 1] == 0) {
					map[x][y - 1] = 2;
				}
			}
		}
	}
	
}
int main(void) {
	memset(visit, 0, sizeof(visit));
	memset(visit2, 0, sizeof(visit2));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				visit[i][j] = 1;
				q.push(make_pair(i, j));
			}
		}
	}
	bfs();
	spread();
	int cnt = 0;
	cout << '\n' << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;

}