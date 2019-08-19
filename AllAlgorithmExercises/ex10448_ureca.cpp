#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool is_eureca(int num,vector<int> output) {
		for (int a = 0; a * (a + 1) / 2 <= num; a++) {
			for (int b = 0; b * (b + 1) / 2 <= num; b++) {
				for (int c = 0; c * (c + 1) / 2 <= num; c++) {
					if (output[a] + output[b] + output[c] == num) {
						return true;
					}
				}
			}
		}
		return false;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	vector<int> k;
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		k.push_back(num);
	}
	int maxVal = 0;
	for (int i = 0; i < k.size(); i++)
	{
		maxVal = max(maxVal, k[i]);
	}
	vector<int> output;
	for (int i = 1; i<= 45; i++) {
		output.push_back(i*(i + 1) / 2);
	}
	for (int i = 0; i < k.size(); i++) {
		if (is_eureca(k[i], output)) {
			cout << 1 << '\n';
		}
		else
			cout << 0 << '\n';
	}
	return 0;
}
