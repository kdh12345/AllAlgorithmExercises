#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int arr[10];
	for (int i = 0; i < 10; i++)
		cin >> arr[i];
	vector<int> v;//나머지 담는칸
	for (int i = 0; i < 10; i++) {
		v.push_back(arr[i] % 42);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	cout << v.size() << '\n';
	return 0;
}