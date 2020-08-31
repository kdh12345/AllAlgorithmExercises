#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp[31][31];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		int n, m;
		cin >> n >> m;
		for (int i = 0; i <= m; i++) {
			dp[1][i] = i;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= m; j++) {
				for (int k = j; k >= i; k--) {
					dp[i][j] = dp[i][j] + dp[i - 1][k - 1];
				}
			}
		}
		cout << dp[n][m] << '\n';
	}
	return 0;
}