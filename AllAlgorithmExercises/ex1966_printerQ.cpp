#include <iostream>
#include <queue>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;//테스트 케이스
	cin >> t;
	deque<int> dq;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			dq.push_back(num);
		}
		bool chk = true;
		while (!dq.empty()) {
			chk = true;
			for (int j = 1; j < dq.size(); j++) {
				if (dq.front() < dq[j]) {
					chk = false;
					break;
				}
			}
			if (chk) {
				cnt++;
				if (m == 0) {
					break;
				}
				dq.pop_front();
				m--;
				if (m < 0)
					m = dq.size() - 1;
			}
			else {
				int number = dq.front();
				dq.pop_front();
				dq.push_back(number);
				m--;
				if (m < 0)
					m = dq.size() - 1;
			}
		}
		cout << cnt << '\n';
		dq.clear();
	}


	return 0;
}