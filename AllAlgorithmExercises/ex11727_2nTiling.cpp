#include <iostream>
using namespace std;
long long dp[1001];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + 2*dp[i - 2]) % 10007;
		
	}
	cout << dp[n] << '\n';
	return 0;
}