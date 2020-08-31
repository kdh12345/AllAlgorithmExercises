#include <iostream>
using namespace std;
int dp[31];
//n=4,5,6...����� ���� �ϸ鼭 ����� ���� �����Ͽ� ��Ģ�� ã�� ��ȭ���� �����.
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	//n�� Ȧ���� 2x1, 1x2 ������ Ÿ���̶� ä�� �� ����.
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) {
			dp[i] += dp[i - j] * 2;//n=4�϶� �����ִ� ���ã��
		}
	}
	cout << dp[n] << '\n';
	return 0;
}