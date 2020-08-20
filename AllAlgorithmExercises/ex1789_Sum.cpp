#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long s;
	cin >> s;
	long long ans = 0;
	for (int i = 1; i <= s; i++) {
		s -= i;
		ans++;
	}
	cout << ans << '\n';
	return 0;
}