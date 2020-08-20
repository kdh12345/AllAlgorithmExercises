#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
vector<int> parent(51);
vector<vector<int>> arr(50);
int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		int y = find(parent[x]);
		parent[x] = y;
		return y;
	}
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);

	parent[y] = x;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	vector<int> know;
	int number;
	cin >> number;
	while (number--) {
		int t;
		cin >> t;
		know.push_back(t);

	}
	
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		int now=0;
		int prev=0;
		for (int j = 0; j < num; j++) {
			if (j >= 1) {
				prev = now;
				cin >> now;
				merge(prev, now);//서로소 집합 만든다.
			}
			else {
				cin >> now;
			}
			arr[i].push_back(now);
		}
	}
	for (auto lists : arr) {
		bool flag = false;
		for (auto conn : lists) {
			if (flag)
				break;
			for (auto a : know) {
				if (find(conn) == find(a)) {
					flag = true;//똑같은 번호있다.
					break;
				}
			}
		}
		if (flag)
			m--;
	}
	cout << m << '\n';
	return 0;
}