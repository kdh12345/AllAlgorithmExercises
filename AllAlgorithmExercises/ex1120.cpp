#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a, b;
	cin >> a >> b;// 공백으로 구분
	int ans = 51;//max 길이 50
	//알파벳추가는 최대한같게 비교한다음 a의 빈자리는 b의 빈자리에 해당하는 알파벳으로 채운다.(가정)
	for (int dis = 0; dis <= b.length() - a.length(); dis++) {
		int cnt = 0;//다른거 세기
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[dis + i])
				cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}