#include <iostream>
using namespace std;
int t[21] = { 0, };
int p[21] = { 0, };
int n;
int ans = 0;
void exit_func(int day, int sum) {
	if (day == n + 1) {
		if (ans < sum)
			ans = sum;
		return;
	}
	if (day > n + 1) {//불가능한경우
		return;
	}
	exit_func(day + 1, sum);//상담x
	exit_func(day + t[day], sum + p[day]);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	exit_func(1, 0);
	cout << ans << '\n';
	return 0;
}