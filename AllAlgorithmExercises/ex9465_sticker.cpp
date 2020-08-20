#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[2][100001];
int dp[2][100001];
int solution() {

	int total = 0;
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[0][1] = arr[0][1];
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++) {
		dp[0][i] = max(dp[1][i - 1], dp[1][i - 2])+arr[0][i];
		dp[1][i] = max(dp[0][i - 1], dp[0][i - 2])+ arr[1][i];
	}
	total = max(dp[0][n], dp[1][n]);
	return total;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		int ans = solution();
		cout << ans << '\n';
		memset(arr, 0, sizeof(arr));
	}
	
	return 0;
}