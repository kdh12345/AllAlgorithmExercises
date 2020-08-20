#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];
int dist[501][501];
const int dx[4] = {0,-1,0,1};
const int dy[4] = {1,0,-1,0};
int n;
int solve(int x, int y) {
	if (dist[x][y])
		return dist[x][y];
	dist[x][y] = 1;//시작점도 세 줘야 한다.
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (arr[x][y] < arr[nx][ny]) {
				dist[x][y] = max(dist[x][y], solve(nx, ny) + 1);
			}
		}
	}
	return dist[x][y];
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int Max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int ans = solve(i, j);
			if (Max < ans)
				Max = ans;
		}
	}
	cout << Max << '\n';
	return 0;
}