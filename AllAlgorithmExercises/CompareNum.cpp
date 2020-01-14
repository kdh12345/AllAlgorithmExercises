#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> a >> b;
	if (a > b)
		cout << '>' << '\n';
	else if (a < b)
		cout << '<' << '\n';
	else
		cout << "==" << '\n';
	return 0;
}