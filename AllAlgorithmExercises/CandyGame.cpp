#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char board[51][51];
int visited[51][51];
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };
int n;
int sol() {
	vector<int> v;
	int result = 1;
	int len = 1;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (board[x][y] == board[x][y + 1])
				len++;
			else {
				result = max(result, len);
				len = 1;
			}

		}
		result = max(result, len);
		len = 1;
		for (int y = 0; y < n; y++) {
			if (board[y][x] == board[y + 1][x])
				len++;
			else {
				result = max(result, len);
				len = 1;
			}
		}
		result = max(result, len);
		len = 1;
	}
	return result;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int MaxVal = 1;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			for (int d = 0; d < 2; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (!board[x][y])
						continue;
					swap(board[x][y], board[nx][ny]);
					MaxVal = max(MaxVal, sol());
					swap(board[x][y], board[nx][ny]);
				}
			}
		}
	}
	cout << MaxVal << '\n';
	return 0;
}