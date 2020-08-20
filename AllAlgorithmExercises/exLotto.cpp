#include <iostream>
#include <vector>
using namespace std;
int main() {
	char input[100];
	cin >> input;
	bool flag = true;
	int res = 0;
	vector<int> v;
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] >= 48 && input[i] <= 57) {
			res = res * 10 + (input[i] - 48);
		}
		else {
			v.push_back(res);
			res = 0;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < 1 || v[i]>45) {
			flag = false;
			break;
		}
	}
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] > v[i + 1]) {
			flag = false;
			break;
		}
	}
	if (flag == 0) {
		cout << "false" << '\n';
	}
	else {
		cout << "true" << '\n';
	}
	return 0;
}