#include <iostream>
#include <cstring>
using namespace std;

int r, c;
const int dx[3] = { -1,0,1 };
const int dy[3] = { 1,1,1 };
char arr[10001][501];
bool visited[10001][501];
int ans;
bool chk;
void dfs(int x,int y) {
	
	if (y == c - 1) {
		ans++;
		chk = true;
		return;
	}
	
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < r && 0 <= ny && ny < c) {
			if (arr[nx][ny] == '.' && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				dfs(nx, ny);
				if (chk)
					return;
			}
		}
	}
	
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		chk = false;
		dfs(i, 0);
	}
	cout << ans << '\n';
	return 0;
}