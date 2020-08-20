#include <iostream>
using namespace std;
int arr[5001];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		arr[i] = i;
	int pos = 0;
	cout << "<";
	while (n>0) {
		pos = (pos + k) % n;
		if (pos == 0)
			pos = n;
		if (n == 1) {
			cout << arr[pos];
		}
		else {
			cout << arr[pos] << ", ";
			for (int i = pos; i < n; i++) {
				arr[i] = arr[i + 1];
			}
			pos--;
		}
		n--;
		
	}
	cout << ">";
	return 0;
}