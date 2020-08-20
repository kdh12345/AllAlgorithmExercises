#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	vector<long long> v(n+1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + v[j]);
		}
	}
	long long ans = dp[n];
	cout << ans << '\n';
	return 0;
}