#include <iostream>
using namespace std;

int dp[101][10];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int sum = 0;
	int n;
	cin >> n;
	for (int i = 1; i < 10; i++)//startnum: 1~9
		dp[1][i] = 1;
	for (int i = 2; i <=n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][0] = (dp[i-1][1]) % 1000000000;
			}
			else if (j == 9) {
				dp[i][9] = (dp[i-1][8]) % 1000000000;
			}
			else {
				dp[i][j] = (dp[i - 1][j-1] + dp[i - 1][j+1]) % 1000000000;
			}
		}
	}//n까지 모든 경우의 수(개수)
	for (int i = 0; i < 10; i++) {
		sum =(sum+dp[n][i])%1000000000;
	}
	cout << sum << '\n';
	return 0;
}