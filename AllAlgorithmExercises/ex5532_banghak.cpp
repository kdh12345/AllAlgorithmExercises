#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int l, a, b, c, d;
	//a 국어 b 수학 c 국어 최대 d 수학 최대
	cin >> l;
	cin >> a; cin >> b;
	cin >> c; cin >> d;
	int korea_day = a / c;
	int math_day = b / d;
	if (a % c != 0) {
		korea_day++;
	}if (b % d != 0) {
		math_day++;
	}
	int ans = max(korea_day, math_day);
	ans = l - ans;
	cout << ans << '\n';
	return 0;
}