#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;//pop 마다 count
	deque<int> dq;
	bool check = true;//1번 2번 구분
	int m = location;
	int len = priorities.size();
	for (int i = 0; i < len; i++) {
		dq.push_back(priorities[i]);
	}
	while (!dq.empty()) {
		check = true;
		for (int h = 1; h < dq.size(); h++) {
			if (dq.front() < dq[h])
			{
				check = false;
				break;
			}
		}//h
		if (check) {
			dq.pop_front();
			answer++;
			if (m == 0) {
				return answer;
			}
			
			if (m > 0)
				m--;
			else
				m = dq.size() - 1;
		}
		else if (!check) {
			int n = dq.front();
			dq.pop_front();
			dq.push_back(n);
			if (m > 0)
				m--;
			else
				m = dq.size() - 1;
		}
		
	}//dq empty
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int loc;
	cin >> loc;
	vector<int> input;
	for (int i = 0; i < 4; i++) {
		int n;
		cin >> n;
		input.push_back(n);
	}
	int ans = solution(input, loc);
	cout << ans << '\n';
	return 0;
}