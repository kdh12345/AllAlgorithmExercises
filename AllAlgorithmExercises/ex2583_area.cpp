#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int map[101][101];
int visit[101][101];
int ex, ey;//끝점
int m, n, k;
queue<pair<int, int>> q;
vector<int> ans;
int area=0;
void bfs(int sx,int sy) {
	int total = 0;
	int x, y;
	map[sx][sy] = 1;
	q.push(make_pair(sx, sy));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		total++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < m && 0 <= ny && ny < n) {
				if (map[nx][ny] == -1) {
					map[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	ans.push_back(total);
	area++;
}
int main(void) {
	memset(map, -1, sizeof(map));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int sx, sy;//시작점
		cin >> sx >> sy >> ex >> ey;
		for (int k = ey - 1; k >= sy; k--) {
			for (int j = ex - 1; j >= sx; j--) {
				map[k][j] = 0;
			}
		}//음영부분은 0으로+ 컴퓨터의 배열 접근 순서가 반대로 있을때 반복문 돌리는 방법(즉 우리가 일반적으로 쓰는 좌표평면일때)
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == -1) {
				bfs(i, j);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << area << '\n';
	for (unsigned int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}