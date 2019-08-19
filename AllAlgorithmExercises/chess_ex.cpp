#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char chess[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> chess[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[i][j] == 'F') {
				if (i % 2 == 0 && j % 2 == 0) {
					cnt++;
				}
				else if (i % 2 == 1) {
					if (j % 2 == 1) {
						cnt++;
					}


				}
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}