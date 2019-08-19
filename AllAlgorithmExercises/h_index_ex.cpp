#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*int solution(vector<int> citations) {
	int answer = 0;
	if (citations.size() == 1) {
		answer = 1;
		return answer;
	}
	vector<int> h_idx;
	for (int i = 0; i < citations.size(); i++) {
		h_idx.push_back(i);
	}
	//1.오름 차순으로 2~3가지의 경우 테스트
	//2.내림 차순으로 2~3가지의 경우 테스트
	sort(citations.begin(), citations.end(),greater<int>());
	int cnt = 0;
	for (int i = 0; i < citations.size(); i++) {
		if (h_idx[i] >= citations[i]) {
			break;
		}
		cnt++;
	}
	answer = cnt;
	return answer;
}*/
int solution(vector<int> citations) {
	int answer = 0;
	vector<int> h_idx;

	//1.오름 차순으로 2~3가지의 경우 테스트
	//2.내림 차순으로 2~3가지의 경우 테스트
	sort(citations.begin(), citations.end(), greater<int>());
	for (int i = 0; i < citations.size(); i++) {
		h_idx.push_back(i);
	}
	for (int i = 0; i < citations.size(); i++) {
		if (h_idx[i] + 1 > citations[i]) {
			return i;
		}
	}
	answer = citations.size();
	return answer;
}
int main(void) {
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> num;
	for (int i = 0; i < n; i++) {
		int n;
		cin >> n;
		num.push_back(n);
	}
	int ans = solution(num);
	cout << ans << '\n';
	return 0;
}