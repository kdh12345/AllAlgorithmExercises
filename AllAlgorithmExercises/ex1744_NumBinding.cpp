#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;
vector<int> plus_num;
vector<int> minus_num;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int one = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num <= 0) {
			minus_num.push_back(num);
		}
		else if (num == 1) {
			one++;
		}
		else if (num > 0) {
			plus_num.push_back(num);
		}
		
		
	}
	int ans = 0;
	sort(plus_num.begin(), plus_num.end(),greater<int> ());
	sort(minus_num.begin(), minus_num.end());
	for (int i = 0; i < plus_num.size(); i += 2) {
		if (i + 1 < plus_num.size())
			ans += plus_num[i] * plus_num[i + 1];
		else
			ans += plus_num[i];
	}
	for (int i = 0; i < minus_num.size(); i += 2) {
		if (i + 1 < minus_num.size())
			ans += minus_num[i] * minus_num[i + 1];
		else
			ans += minus_num[i];
	}
	cout << ans+one << '\n';
	return 0;
}