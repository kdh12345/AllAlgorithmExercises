#include <iostream>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num;
	cin >> num;
	int one = num / 10;
	int two = num % 10;
	int cnt = 0;
	int r = 0;
	while (true) {
		int tmp = one + two;
		r = two * 10 + tmp % 10;
		cnt++;
		if (num == r)
			break;
		one = r / 10;
		two = r % 10;
	}
	cout << cnt << '\n';

	return 0;
}