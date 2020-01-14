#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int cnt;
vector<pair<int, int> > v;
void move(int from, int to) {
	//cout << from << ' ' << to << '\n';
	v.push_back(make_pair(from, to));
}
void hanoi(int n, int from, int by, int to) {
	if (n==1) {
		move(from, to);
	}
	else {
		hanoi(n - 1, from, to, by);
		move(from, to);
		hanoi(n - 1, by, from, to);
	}
	cnt++;
	return;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	hanoi(n, 1,2,3);
	cout << cnt << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}