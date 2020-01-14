#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool prime[123456 * 2 + 1];
int main(void) {
	memset(prime, false, sizeof(prime));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 2; i * i <= 123456 * 2; i++) {
		if (prime[i] == false) {
			for (int j = i * i; j <= 123456 * 2; j += i) {
				prime[j] = true;
			}
		}
	}
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {

			if (prime[i] == false)
			{
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}