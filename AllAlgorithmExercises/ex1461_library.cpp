#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
void go(vector<int> v){
	sort(v.begin(), v.end());
	int pos = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) {//기준점 0이 어딘지 구한다.
			pos = i;
			break;
		}
	}
	int ans = 0;
	//음수
	for (int i = 0; i < pos; i+=m) {
		ans += abs(v[i]*2);
	}
	//양수
	for (int i = n; i > pos; i -= m) {
		ans += v[i]*2;
	}
	ans -= max(abs(v[0]), abs(v[n]));//왕복이 아니다.
	cout << ans << '\n';
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<int> v(n+1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	go(v);
	return 0;
}