#include <iostream>
using namespace std;

bool check_row[10][10];//왼쪽인덱스는 index, 오른쪽은 숫자(1~9)
bool check_col[10][10];
bool check_three[10][10];
int Map[10][10];
int square(int x, int y) {
	return (x / 3) * 3 + y / 3;
}
void sudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << Map[i][j] << ' ';
		}
		cout << '\n';
	}
}
bool check(int n) {
	if (n == 81) {
		sudoku();
		return true;
	}
	int x = n / 9;//행
	int y = n % 9;
	if (Map[x][y] != 0) {
		return check(n + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (check_row[x][i] == false && check_col[y][i] == false && check_three[square(x, y)][i] == false) {
				check_row[x][i] = true;
				check_col[y][i] = true;
				check_three[square(x, y)][i] = true;
				Map[x][y] = i;
				if (check(n + 1)) {
					return true;
				}
				Map[x][y] = 0;
				check_row[x][i] = false;
				check_col[y][i] = false;
				check_three[square(x, y)][i] = false;
			}
		}
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> Map[i][j];
			if (Map[i][j] != 0) {
				check_row[i][Map[i][j]] = true;
				check_col[j][Map[i][j]] = true;
				check_three[square(i, j)][Map[i][j]] = true;
			}
		}
	}
	check(0);
	return 0;
}