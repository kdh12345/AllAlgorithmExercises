#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void solveCmd(string cmd,deque<int> dq) {
	bool reve = false;
	bool check = true;
	for (int i = 0; i < cmd.length(); i++) {
		if (cmd[i] == 'R') {
			reve = !reve;
		}
		else if (cmd[i] == 'D') {
			if (!dq.empty()) {
				if (reve) {
					dq.pop_back();
				}
				else if (!reve) {
					dq.pop_front();
				}
			}
				
			else {
				check = false;
				break;
			}
		}
	}
	if (check) {
		cout << "[";
		if (reve)
		{
			reverse(dq.begin(), dq.end());
		}
		for (int i = 0; i < dq.size(); i++) {
			cout << dq[i];
			if (i < dq.size() - 1)
				cout << ",";
		}
		cout <<"]"<<'\n';
	}
	else {
		cout << "error" << '\n';
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string cmd;
		cin >> cmd;
		int n;
		cin >> n;
		string word;
		cin >> word;
		int res = 0;
		deque<int> dq;
		for (int i = 0; i<word.length(); i++) {
			if (word[i] >= 48 && word[i] <= 57) {
				res = res * 10 + (word[i] - 48);
			}
			else {
				if (res > 0)
					dq.push_back(res);
				res = 0;
			}
		}
		solveCmd(cmd, dq);

	}
	return 0;
}