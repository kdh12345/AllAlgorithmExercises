#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct sorting {
	int age;
	string word;
	int cnt;
};
bool cmp(const sorting s1, const sorting s2) {
	if (s1.age < s2.age) {
		return true;
	}
	else if (s1.age == s2.age) {
		return s1.cnt < s2.cnt;
	}
	else
		return false;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<sorting> v;
	for (int i = 0; i < n; i++) {
		int age;
		string word;
		cin >> age >> word;
		v.push_back({ age,word,i });
	}
	sort(v.begin(), v.end(),cmp);
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i].age == v[i + 1].age) {
			if (v[i].cnt > v[i + 1].cnt) {
				swap(v[i].age, v[i + 1].age);
				swap(v[i].word, v[i + 1].word);
				swap(v[i].cnt, v[i + 1].cnt);
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].age << ' ' << v[i].word << '\n';
	}
	return 0;
}