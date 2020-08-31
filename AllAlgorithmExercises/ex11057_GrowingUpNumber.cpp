#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][10] = { {0},{1,1,1,1,1,1,1,1,1,1} };
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int now = 0; now < 10; now++) {
			for (int prev = now; prev < 10; prev++) {
				dp[i][now] += dp[i - 1][prev]% 10007;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[n][i] % 10007;
	}
	ans = ans % 10007;
	cout << ans << '\n';
	return 0;
}