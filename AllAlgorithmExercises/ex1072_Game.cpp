#include <iostream>
using namespace std;

int MaxVal = 1000000000;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long x, y, z;
	cin >> x >> y;
	z = (100 * y) / x;
	if (z >= 99) {
		cout << -1 << '\n';
		return 0;
	}
	long long left, right, testZ;
	left = 0;
	right = MaxVal;
	while (left <= right) {
		long long mid= left + (right - left) / 2;
		testZ = (y + mid) * 100 / (x + mid);
	
		if (z < testZ) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left << '\n';

	return 0;
}