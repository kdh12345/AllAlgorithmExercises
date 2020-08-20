#include <iostream>
#include <string>
#include <cmath>
using namespace std;
char alpha1[26];
char alpha2[26];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b;
	cin >> a >> b;
	int cnt = 0;
	for (int i = 0; i < a.length(); i++)
		alpha1[a[i] - 'a']++;
	for (int i = 0; i < b.length(); i++)
		alpha2[b[i] - 'a']++;
	for (int i = 0; i < 26; i++) {
		if (alpha1[i] != alpha2[i])
			cnt += abs(alpha2[i] - alpha1[i]);
	}
	cout << cnt << '\n';
	return 0;
}