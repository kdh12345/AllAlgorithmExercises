#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


int prime[10000];
int visit[10000];
queue<pair<int,int> > q;// prime과 cnt
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(prime, 0, sizeof(prime));
		int Start, End;
		cin >> Start >> End;
		for (int i = Start; i<= End; i++) {
			prime[i] = i;
		}
		for (int i = Start; i * i <= End; i++) {
			if (prime[i] == 0)
				continue;
			for (int j = i + i; j <= End; j += i) {
				prime[j] = 0;
			}
		}//에라토스테네스의 체
		int pre = Start;
		int cnt = 0;
		int num = 1;//자리수
		for (int i = pre; i <= End;) {
			if (prime[i] == i && !visit[i])
			{
				cout << i << '\n';
				q.push(make_pair(i, cnt + 1));
				cnt++;
				visit[i] = 1;
				
			}
			if (num == 1) {
				
				i += 1000;
				if (i / 1000 == 9)
				{
					i = pre;
					num = 2;
				}
			}//첫째자리수 변경
			else if (num == 2) {
				i += 100;
				if ((i % 1000) / 100 == 0) {
					i = pre;
					num = 3;
				}
			}//둘째 자리 변경
			else if (num == 3) {
				i += 10;
				if ((i % 100) / 10 == 0) {
					i = pre;
					num = 4;
				}
			}
			else if (num == 4) {
				i++;
				if (i % 10 == 0)
				{
					break;
				}
			}

		}
		if (Start == End) {
			cout << 0 << '\n';
		}
		else if (Start != End) {
			cout << cnt << '\n';
			while (!q.empty()) {
				q.pop();
			}
		}
	}
	

	return 0;
}
