#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= k; i++)
		dp[i] = 10001;//동전의 최대갯수로 세팅
	for (int m : v) {
		for (int i = m; i <= k; i++) {
			if (dp[i] > dp[i - m] + 1) {
				dp[i] = dp[i - m] + 1;
			}
		}
	}
	int ans = 0;
	if (dp[k] == 10001)
		ans = -1;
	else
		ans = dp[k];
	cout << ans << '\n';
	return 0;
}