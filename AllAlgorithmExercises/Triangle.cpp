#include <iostream>
#include <algorithm>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		if (a >= b)
			swap(a, b);
		if (a >= c)
			swap(a, c);
		if (b >= c)
			swap(b, c);
		if (c * c == a * a + b * b)
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
		

	}


	return 0;
}