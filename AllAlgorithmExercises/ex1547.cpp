#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> m;
	int cup[4] = { 0,1,2,3 };
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		if (x == y)
			continue;
		for (int k = 1; k <= m; k++) {
			int tmp = 0;
			if (x == cup[k]) {
				cup[k] = y;

			}else if (y == cup[k]) {
				cup[k] = x;
			}
		}
	}
	cout << cup[1] << '\n';
	return 0;
}