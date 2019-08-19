#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	int num = 666;
	int cnt = 0;
	while (true) {
		string s = to_string(num);
		if (s.find("666") != string::npos) {
			cnt++;
		}
		if (cnt == n)
			break;
		num ++;
	}
	cout << num << '\n';
	return 0;

}