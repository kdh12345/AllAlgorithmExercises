#include <iostream>
#include <vector>
using namespace std;
int arr[10001];
void solution() {
	for (int i = 1; i <= 10000; i++) {
		int sum = i;
		int num = i;
		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}
		arr[sum]++;

	}
	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == 0) {
			cout << i << '\n';
		}
	}
}
int main(void) {
	solution();
	return 0;
}