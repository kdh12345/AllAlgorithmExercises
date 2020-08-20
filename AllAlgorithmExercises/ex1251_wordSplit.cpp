#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string ans;
void solve(string tmp, int first, int second) {
	string a = "";
	string b = "";
	string c = "";
	for (int i = 0; i <= first; i++)
		a += tmp[i];
	for (int i = first + 1; i <= second; i++)
		b += tmp[i];
	for (int i = second + 1; i < tmp.length(); i++)
		c += tmp[i];
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(c.begin(), c.end());
	string word = a + b + c;
	if (ans == "")
		ans = word;
	else {
		if (ans > word)
			ans = word;
	}

}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string input;
	cin >> input;
	int len = input.length();
	
	for (int i = 0; i < len-1; i++) {
		for (int j = i; j < len - 1; j++) {
			if (i == j)
				continue;
			solve(input, i, j);
		}
	}
	cout << ans << '\n';
	return 0;
}