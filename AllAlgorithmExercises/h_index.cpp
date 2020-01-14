#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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