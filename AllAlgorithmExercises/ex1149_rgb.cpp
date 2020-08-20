#include <iostream>
#include <algorithm>
using namespace std;

int rgb[1001][3];
int dp[1001][3];
int n;
int solve() {
	for (int i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
	}
	int res = min(dp[n][0], min(dp[n][1], dp[n][2]));
	return res;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> rgb[i][j];
		}
	}
	int ans = solve();
	cout << ans << '\n';
	return 0;
}