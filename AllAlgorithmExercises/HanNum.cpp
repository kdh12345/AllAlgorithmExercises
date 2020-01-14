#include <iostream>
#include <cmath>
using namespace std;


int solution(int n) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i < 100)
			cnt++;
		else if (i < 1000) {
			int x = i / 100;
			int y = (i % 100) / 10;
			int z = (i % 100) % 10;
			if (x - y == y-z) {
				cnt++;
			}
		}
	}
	return cnt;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num;
	cin >> num;
	int ans = solution(num);
	cout << ans << '\n';
	return 0;
}