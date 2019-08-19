#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> calc(vector<int>& a,int index, int cur, int plus, int minus, int mul, int div) {
	int n = a.size();
	if (index == n) {//정답 찾음!!
		return make_pair(cur, cur);
	}
	vector<pair<int, int>> res;
	if (plus > 0) {
		res.push_back(calc(a,index + 1, cur + a[index], plus - 1, minus, mul, div));
	}
	if (minus > 0) {
		res.push_back(calc(a,index + 1, cur - a[index], plus, minus - 1, mul, div));
	}
	if (mul > 0) {
		res.push_back(calc(a,index + 1, cur * a[index], plus, minus, mul - 1, div));
	}
	if (div > 0) {
		res.push_back(calc(a,index + 1, cur / a[index], plus, minus, mul, div - 1));
	}
	auto ans = res[0];
	for (auto p : res) {
		if (ans.first < p.first) {
			ans.first = p.first;//최대
		}
		if (ans.second > p.second) {
			ans.second = p.second;//최소
		}
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;
	auto p = calc(a,1, a[0], plus, minus, mul, div);
	//auto는 선언과 동시에 초기화를 하여야한다.
	cout << p.first << '\n';
	cout << p.second << '\n';
	return 0;
}