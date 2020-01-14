#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	double m, n;
	cin >> m >> n;
	vector<double> ans;
	for (double i = m; i <= n; i++) {
		if (int(sqrt(i)) == pow(i,0.5)) {
			ans.push_back(i);
		}
	}
	double Min = 987654321;
	int len = ans.size();
	double total = 0;
	if (len != 0) {
		for (int i = 0; i < len; i++) {
			if (Min > ans[i])
				Min = ans[i];
			total += ans[i];
		}
		cout << total << '\n' << Min << '\n';
	}
	else
		cout << -1 << '\n';
	return 0;
}