#include <iostream>
using namespace std;
int solution(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return solution(n - 1) + solution(n - 2);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int ans = solution(n);
	cout << ans << '\n';
	return 0;
}