#include <iostream>
#include <string>
using namespace std;

int word_length(string s) {
	int len = 0;
	for (int i = 0; i < s.length(); i++)
		len++;
	return len;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	getline(cin, str);
	int ans = word_length(str);
	cout << ans << '\n';
	return 0;
}