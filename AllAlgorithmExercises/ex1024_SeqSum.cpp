#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, l;
	cin >> n >> l;
	int start = -1;
	int end = -1;
	for (int i = l; i <= 100; i++) {
		int sum = (i - 1) * i / 2;
		if ((n - sum) % i == 0 && (n - sum) / i >= 0) {
			start = (n - sum) / i;
			end = i;
			break;//연속 수열 발견 종료
		}
	}
	if (start == -1) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 0; i < end; i++) {
			cout << start + i << ' ';
		}
		cout << '\n';
	}
	return 0;
}