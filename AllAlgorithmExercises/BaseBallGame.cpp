#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool check[1000];
	memset(check, true, sizeof(check));
	for (int i = 123; i < 1000; i++) {
		int x = i / 100;
		int y = (i % 100) / 10;
		int z = (i % 100) % 10;
		if (x == y || x == z || y == z)
			check[i] = false;
		if (x == 0 || y == 0 || z == 0)
			check[i] = false;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num, s, b;//s strike b ball
		cin >> num >> s >> b;
		if (s == 3) {
			cout << 1 << '\n';
			return 0;
		}
		string n = to_string(num);
		int x = num / 100;
		int y = (num % 100) / 10;
		int z=(num % 100) % 10;
		for (int j = 123; j < 1000; j++) {
			
			if (check[j] == true) {
				int strike = 0;
				int ball = 0;
				int jx = j / 100;
				int jy = (j % 100) / 10;
				int jz = (j % 100) % 10;
				if (x == jx)
					strike++;
				if (y == jy)
					strike++;
				if (z == jz)
					strike++;
				if (x == jy||x==jz)
					ball++;
				if (y == jx||y==jz)
					ball++;
				
				if (z == jx||z==jy)
					ball++;
				if (strike != s || ball != b) {
					check[j] = false;
				}
			}
			
		}
	}
	int cnt = 0;
	for (int i = 123; i < 1000; i++) {
		if (check[i] == true)
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}