#include <iostream>
using namespace std;
int n;
bool check_row[15];
bool check_col[15];
bool check_dig1[30];
bool check_dig2[30];
int ans;
bool check(int row, int col) {
	if (check_row[row])
		return false;
	if (check_col[col])
		return false;
	if (check_dig1[row + col])
		return false;
	if (check_dig2[row - col + n])
		return false;
	return true;
}
void queen(int row) {
	if (row == n) {
		ans += 1;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check(row, i)) {
			check_row[row] = true;
			check_col[i] = true;
			check_dig1[row + i] = true;
			check_dig2[row - i + n] = true;
			queen(row + 1);
			check_row[row] = false;
			check_col[i] = false;
			check_dig1[row + i] = false;
			check_dig2[row - i + n] = false;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	queen(0);
	cout << ans << '\n';
	return 0;
}
