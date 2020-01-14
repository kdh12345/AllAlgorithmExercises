#include <iostream>
using namespace std;
int n;
bool c[15][15];
int ans;
bool check(int row,int col) {
	// -(row)
	for (int i = 0; i < n; i++) {
		if (i == col)
			continue;
		if (c[row][i])//지나가지 x하는 경우
			return false;
	}
	// |(col)
	for (int i = 0; i < n; i++) {
		if (i == row)
			continue;
		if (c[i][col])//지나가지 x하는 경우
			return false;
	}
	//  \(왼쪽 대각선)
	int x = row - 1;
	int y = col - 1;
	while (x >= 0 && y >= 0) {
		if (c[x][y])//지나가지 x하는 경우
			return false;
		x--;
		y--;
	}
	x = row - 1;
	y = col + 1;
	while (x >= 0 && y < n) {
		if (c[x][y])//지나가지 x하는 경우
			return false;
		x--;
		y++;
	}
	return true;
}
void queen(int row) {
	if (row == n) {
		ans += 1;
		return;
	}
	for (int i = 0; i < n; i++) {
		c[row][i] = true;
		if (check(row,i))
			queen(row + 1);
		c[row][i] = false;
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	queen(0);
	cout << ans << '\n';
	return 0;
}
