#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int Lstock = stock;
	int idx = 0;
	priority_queue<int> pq;
	for (int i = 0; i < k; i++)
	{
		if (idx < dates.size() && dates[idx] == i) {
			pq.push(supplies[idx]);
			idx++;
		}
		if (Lstock == 0) {
			Lstock += pq.top();
			pq.pop();
			answer++;
		}
		Lstock--;
	}
	
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int stock;
	cin >> stock;
	vector<int> day(3);
	vector<int> supply(3);
	for (int i = 0; i < 3; i++) {
		cin >> day[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> supply[i];
	}
	int k;
	cin >> k;
	int ans = solution(stock, day, supply, k);
	cout << ans << '\n';
	return 0;
}