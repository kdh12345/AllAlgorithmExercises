#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int up[100001];
int down[100001];
int res = 200001;
int cnt;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, h;
	cin >> n >> h;
	for (int i = 0; i < n / 2; i++)
		cin >> up[i] >> down[i];
	sort(up, up + (n / 2));
	sort(down, down + (n / 2));
	for (int i = 1; i <= h; i++) {
		int val = lower_bound(up, up + (n / 2), i) - up;//석순
		val += upper_bound(down, down + (n / 2), h - i) - down;//종유석
		val = n - val;
		if (val == res) {
			cnt++;
		}
		else if (res > val)
		{
			res = val;
			cnt = 1;
		}
	}
	cout << res << ' ' << cnt << '\n';
	return 0;
}