#include <iostream>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int H, M;
	cin >> H >> M;
	if (M - 45 < 0) {
		M += 60;
		M -= 45;
		H--;
	}
	else
		M -= 45;
	if (H < 0)
		H = 23;
	cout << H << ' ' << M << '\n';
	return 0;
}