#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int arr[9];
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	int Max = 0;
	int idx = 0;
	for (int i = 0; i < 9; i++) {
		if (Max < arr[i]) {
			Max = arr[i];
			idx = i;
		}
	}
	cout << Max << '\n' << idx+1 << '\n';

	return 0;
}