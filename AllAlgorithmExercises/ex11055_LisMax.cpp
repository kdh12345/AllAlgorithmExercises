#include <iostream>
using namespace std;

int dp[1001];
int arr[1001];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (sum < dp[j]) {
					sum = dp[j];
				}
			}
		}
		dp[i] = sum + arr[i];//부분 증가수열의 합 저장
		if (ans < dp[i])
			ans = dp[i];
	}
	cout << ans << '\n';

	return 0;
}