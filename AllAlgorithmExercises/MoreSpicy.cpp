#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int,vector<int>,greater<int> > dq;
	int k = K;
	for (int i = 0; i < scoville.size(); i++) {
		dq.push(scoville[i]);
	}
	int one = 0;
	int two = 0;
	while (dq.top()<k&&dq.size()>1) {
		one = dq.top();
		dq.pop();
		two = dq.top();
		dq.pop();
		dq.push(one + 2 * two);
		answer++;
	}
	if (dq.top()<k) {//끝내 k를 넘지 못함
		answer = -1;
	}
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> v;
	int k;
	cin >> k;
	for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	int ans = solution(v,k);
	cout << ans << '\n';
	return 0;
}