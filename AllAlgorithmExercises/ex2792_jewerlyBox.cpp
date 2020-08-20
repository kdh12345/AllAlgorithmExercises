#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long arr[300000];
bool check(long long mid,int m,int n) {
	int num = 0;
	for (int i = 0; i < m; i++) {
		num += arr[i] / mid;//RR, RR, BB,...ÂÉ°³´Â ½Ä
		if (arr[i] % mid)
			num++;
	}
	if (n >= num)
		return true;
	return false;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	long long low = 0;
	long long high = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
		if (high < arr[i])
			high = arr[i];
	}
	long long ans = 1000000000;
	while (low <= high) {
		long long mid = low + (high - low) / 2;
		if (check(mid,m,n)) {
			ans = min(ans, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}