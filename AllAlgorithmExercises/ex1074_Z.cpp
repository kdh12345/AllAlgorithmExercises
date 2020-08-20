#include <iostream>
#include <cmath>
using namespace std;
int n, r, c;
int cnt;
void solve(int a, int b,int s) {
	if (a == r && b == c) {
		cout << cnt << '\n';
		return;
	}
	if (s == 1) {
		cnt++;
		return;
	}
	if (a<=r && r<a+s && b<=c&&c<b+s) {
		solve(a, b, s / 2);
		solve(a, b + s / 2, s / 2);
		solve(a + s / 2, b, s / 2);
		solve(a + s / 2, b + s / 2, s / 2);
	}
	else
	{
		cnt += s * s;
		return;
	}
	
}
void go(int m) {
	solve(0, 0, m);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> r >> c;
	go(pow(2,n));
	return 0;
}