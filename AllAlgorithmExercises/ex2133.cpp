#include <iostream>
using namespace std;
int dp[31];
//n=4,5,6...모양을 직접 하면서 경우의 수를 조사하여 규칙을 찾고 점화식을 만든다.
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	//n이 홀수는 2x1, 1x2 형태의 타일이라 채울 수 없다.
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) {
			dp[i] += dp[i - j] * 2;//n=4일때 숨어있는 모양찾기
		}
	}
	cout << dp[n] << '\n';
	return 0;
}