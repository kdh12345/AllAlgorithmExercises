#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

int chSet[10];
int minVal = INT_MAX;
void check(string num,int k) {
	for (int i = 0; i < 10; i++) {
		if (chSet[i]) {
			string tmp = num + to_string(i);
			int cmp = abs(k - atoi(tmp.c_str())) + tmp.length();
			minVal = min(minVal, cmp);
			if (tmp.length() < 6)//최대가 500,000이기 때문에
				check(tmp, k);
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 10; i++) {
		chSet[i] = 1;
	}
	string word;
	int t;
	cin >> word >> t;
	int number = atoi(word.c_str());
	minVal = min(minVal, abs(100 - number));//무식하게 누르는 경우
	vector<int> v(t);
	for (int i = 0; i < t; i++) {
		cin >> v[i];
		chSet[v[i]] = 0;
	}
	if (word == "100") {
		cout << 0 << '\n';
		return 0;
	}
	if (t < 10) {
		check("",number);
	}
	cout << minVal << '\n';
	return 0;
}