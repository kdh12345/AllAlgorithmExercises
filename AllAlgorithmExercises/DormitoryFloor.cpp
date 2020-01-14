#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int red, brown;
	cin >> red >> brown;
	int total = red + brown;
	//int mul = total;//가로*세로
	//int tmp = brown+5;
	//int plus = tmp;//가로+세로
	int L=0, W=0;
	int w = 0;
	for (int i = 1;i<=sqrt(total) ; i++) {
		if (brown % i == 0)
		{
			w = brown / i;
			if (2 * w + 2 * i + 4 == red) {
				L = i + 2;
				W = w + 2;
				break;
			}
		}
		
	}
	cout << W << ' ' << L << '\n';
	return 0;
}