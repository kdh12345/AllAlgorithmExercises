#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;//√ 
	queue<int> q;
	int max_size = 0;
	int siz = 0;
	int len = truck_weights.size();
	for (int i = 0; i < len; i++) {
		siz = truck_weights[i];
		while (true) {
			if (q.empty()) {
				q.push(siz);
				max_size += siz;
				answer++;
				break;
			}
			if (q.size() == bridge_length) {
				max_size -= q.front();
				q.pop();
			}
			else {
				if (siz + max_size > weight) {
					q.push(0);
					answer++;
				}
				else {
					q.push(siz);
					max_size += siz;
					answer++;
					break;
				}
			}
		}

	}
	answer += bridge_length;
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int len, weight;
	cin >> len >> weight;
	vector<int> v;
	for (int i = 0; i < 1; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int ans = solution(len, weight, v);
	cout << ans << '\n';
	return 0;
}