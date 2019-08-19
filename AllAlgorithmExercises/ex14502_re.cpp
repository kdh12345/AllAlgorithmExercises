#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int map[9][9];
int visit[9][9];
int n, m, ans;

void bfs() {
	int after[9][9] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			after[i][j] = map[i][j];
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (after[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m) {
				if (after[nextX][nextY] == 0) {
					after[nextX][nextY] = 2;
					q.push(make_pair(nextX, nextY));
				}
			}
		}
	}
	int cnt = 0;//ÃÖÁ¾ 0°¹¼ö
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (after[i][j] == 0)
				cnt++;
		}
	}
	ans = max(cnt, ans);
}
void wall_make(int cnt) {
	if (cnt == 3) {//ÃÖ´ë º®ÀÇ °³¼ö 3°³
		bfs();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				wall_make(cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {//ºóÄ­¹ß°ß!!
				map[i][j] = 1;
				wall_make(1);
				map[i][j] = 0;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}