#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000000];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int Max = -987654321;
	int Min = 987654321;
	for (int i = 0; i < n; i++) {
		Max = max(Max, arr[i]);
		Min = min(Min, arr[i]);
	}
	cout << Min << ' ' << Max << '\n';
	return 0;
}