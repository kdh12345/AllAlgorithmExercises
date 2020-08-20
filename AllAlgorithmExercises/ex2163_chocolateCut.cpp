#include <iostream>
#include <algorithm>
using namespace std;
int dp[90001];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	//cout << n * m - 1 << '\n';
	int siz = n * m;
	dp[1] = 0;
	for (int i = 2; i <= siz; i++) {
		int a = i / 2;
		int b = i-a;
		dp[i] = dp[a] + dp[b] + 1;
	}
	cout << dp[siz] << '\n';
	return 0;
}