#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[100001];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int Max = 0;
	int sq = 0;
	for (int i = 1; i <= n; i++) {
		if (sqrt(i) == int(sqrt(i))) {
			Max = i;
			sq = int(sqrt(i));
		}
	}
	for (int i = 1; i <= n; i++)
		dp[i] = i;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j*j<= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n] << '\n';
	return 0;
}