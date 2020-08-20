#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
bool visit[9];
int ans;
vector<int> v;
vector<int> result;
bool check(int num) {
	if (num == 1)
		return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}
void go(int cnt, vector<int> ex) {
	if (cnt > ex.size())
		return;
	if (cnt <= ex.size()) {
		string number = "";
		for (int i = 0; i < v.size(); i++)
			number += (v[i] + '0');
		int prime = atoi(number.c_str());
		if (check(prime)) {
			ans++;
			result.push_back(prime);
		}

	}
	for (int i = 0; i < ex.size(); i++) {
		if (visit[i]) {
			continue;
		}
		visit[i] = true;
		v.push_back(ex[i]);
		go(cnt + 1, ex);
		v.pop_back();
		visit[i] = false;
	}
}
int solution(string number) {
	vector<int> ex;
	for (int i = 0; i < number.length(); i++) {
		int num = number[i] - '0';
		ex.push_back(num);
	}
	go(0, ex);
	sort(result.begin(), result.end());
	if (ans > 0) {
		for (int i = 0; i < result.size() - 1; i++) {
			if (result[i] == result[i + 1]) {
				ans--;
			}
		}
	}
	return ans;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin >> c;
	while (c--) {
		string input;
		cin >> input;
		int answer = solution(input);
		answer--;
		cout << answer << '\n';
		ans = 0;
		v.clear();
		result.clear();
	}
}