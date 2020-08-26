#include <iostream>
using namespace std;
int matrix1[51][51];
int matrix2[51][51];
int n, m;
int transpose() {
	int start_y = 0;
	int start_x = 0;
	int cnt = 0;
	if (n < 3 || m < 3) {
		return -1;
	}
	while (start_x < n) {
		while (start_y < m) {
			if (start_x + 2 < n && start_y+2 < m) {
				for (int i = start_x; i <= start_x + 2; i++) {
					for (int j = start_y; j <= start_y + 2; j++) {
						if (matrix1[i][j] == 0) {
							matrix1[i][j] = 1;
						}
						else if (matrix1[i][j] == 1) {
							matrix1[i][j] = 0;
						}
					}
				}
			}
			bool chk = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (matrix1[i][j] == matrix2[i][j]) {
						chk = true;
					}
					else {
						chk = false;
						cnt++;
						break;
					}
				}
				if (!chk) {
					break;
				}
			}
			start_y++;
			if (chk) {
				cnt++;
				return cnt;
			}
				
		}//start_y<n
		start_x++;
		start_y = 0;
	}
	return cnt;
}
int main(void) {
	cout.tie(0);
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &matrix1[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &matrix2[i][j]);
		}
	}
	int ans=transpose();
	cout << ans << '\n';
	return 0;
}