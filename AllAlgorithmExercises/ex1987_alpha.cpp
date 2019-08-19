#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
char map[21][21];
int visited[21][21];
int check[21][21];//중복체크 2차원배열
int r, c;//세로 r, 가로 c
int cnt = -1;
int ans = 0;
void dfs(int x, int y) {
	visited[0][0] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < r && 0 <= ny && ny < c) {
				if (map[nx][ny] != map[x][y] && visited[nx][ny] == 0) {
					visited[nx][ny] = 1;
					cnt++;
					dfs(nx, ny);
				}
		}
	}
	ans = max(ans, cnt);
}
int main(void) {
	memset(visited, 0, sizeof(visited));
	memset(check, 0, sizeof(check));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	
	
	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}