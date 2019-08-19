#include <iostream>
#include <queue>
using namespace std;
char adj[21][21];
int visit[21][21];
int n, m;
queue<pair<int, int>> q;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt = 0;
int bfs(){
	int nowX, nowY, nextX, nextY;
	while (!q.empty()) {
		nowX = q.front().first;
		nowY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nextX = nowX + dx[i];
			nextY = nowY + dy[i];
			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m) {
				if (adj[nextX][nextY] == '.' && visit[nextX][nextY] == 0) {
					q.push({ nextX,nextY });
					visit[nextX][nextY] = visit[nowX][nowY] + 1;
					cnt++;
				}
			}
		}
	}
	return visit[nowX][nowY];
}
int main(void) {
	memset(visit, 0, sizeof(visit));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> adj[i][j];
			if (adj[i][j] == 'o') {
				visit[i][j] = 1;
				q.push({ i,j });
			}
				
		}
	}
	int ans = bfs();
	if (ans == -1 || cnt > 10)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
	return 0;
}