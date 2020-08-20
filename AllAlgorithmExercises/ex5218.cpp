#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string a, b;
		cin >> a >> b;
		int len = a.length();
		vector<int> v;
		for (int j = 0; j < len; j++) {
			int diff = b[j] - a[j];
			if (diff >= 0) {
				v.push_back(diff);
			}
			else {
				diff += 26;
				v.push_back(diff);
			}
		}
		cout << "Distances: ";
		for (int k = 0; k < v.size(); k++) {
			cout << v[k] << ' ';
		}
		cout << '\n';
	}



	return 0;
}