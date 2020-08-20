#include <iostream>
using namespace std;

int dp[101][100001];
int store[101];
int cost[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;//n은 갯수, m은 최소 확보 바이트 수
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> store[i];
	for (int i = 0; i < n; i++)
		cin >> cost[i];
	dp[0][cost[0]] = store[0];
	int ans = 987654321;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 100000; j++) {
			if (j - cost[i]>=0) {
				if (dp[i][j] < dp[i - 1][j - cost[i]] + store[i]) {
					dp[i][j] = dp[i - 1][j - cost[i]] + store[i];
				}
			}
			if (dp[i][j] < dp[i - 1][j]) {
				dp[i][j] = dp[i - 1][j];
			}
			if (dp[i][j] >= m) {
				if (ans > j) {
					ans = j;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}