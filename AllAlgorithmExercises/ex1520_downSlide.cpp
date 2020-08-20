#include <iostream>
#include <cstring>
using namespace std;

int ans;
int board[501][501];
int dp[501][501];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
int n, m;
int dfs(int x, int y) {
	if (dp[x][y]>-1)
		return dp[x][y];
	if (x<0 || x>=n || y<0 || y>=m)
		return 0;
	if (x == 0 && y == 0)
		return 1;
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (board[x][y] < board[nx][ny]) {
			dp[x][y] += dfs(nx, ny);
		}
	}
	return dp[x][y];
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	int ans = dfs(n-1, m-1);
	cout << ans << '\n';
	return 0;
}