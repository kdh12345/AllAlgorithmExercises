#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int n;
int arr[21][21];
bool check[21];
int min_val = 987654321;
//brute force+dfs
void pick(int r, int cnt) {
	if (cnt == n / 2&&r==n) {//¡æ∑·¡∂∞«
		int start=0,link=0;//start∆¿, link∆¿
		for (int i = 0; i < n; i++) {
			if (check[i] == 0) {
				for (int j = i + 1; j < n; j++) {
					if (check[j] == 0) {
						start += arr[i][j];
						start += arr[j][i];
					}
				}
			}
		}//start∆¿
		for (int i = 0; i < n; i++) {
			if (check[i] == 1) {
				for (int j = i + 1; j < n; j++) {
					if (check[j] == 1) {
						link += arr[i][j];
						link += arr[j][i];
					}
				}
			}
		}//link∆¿
		min_val = min(min_val, abs(link - start));
		return;
	}
	if (r == n)
	{
		return;
	}
	check[r] = 1;
	pick(r+1, cnt + 1);
	check[r] = 0;
	pick(r + 1, cnt);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	pick(0, 0);
	cout << min_val << '\n';
	return 0;
}

