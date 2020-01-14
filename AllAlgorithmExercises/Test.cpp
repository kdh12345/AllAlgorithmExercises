#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int st1[5] = { 1,2,3,4,5 };
	int st2[8] = { 2,1,2,3,2,4,2,5 };
	int st3[10] = { 3,3,1,1,2,2,4,4,5,5 };
	int st1_cnt = 0;
	int st2_cnt = 0;
	int st3_cnt = 0;
	for (int i = 0; i < answers.size(); i++) {
		if (st1[i % 5] == answers[i])
			st1_cnt++;
		if (st2[i % 8] == answers[i])
			st2_cnt++;
		if (st3[i % 10] == answers[i])
			st3_cnt++;
	}
	cout << st1_cnt << ' ' << st2_cnt << ' ' << st3_cnt << '\n';
	int MaxVal = 0;
	int tmp[3];
	tmp[0] = st1_cnt; tmp[1] = st2_cnt; tmp[2] = st3_cnt;
	for (int i = 0; i < 3; i++) {
		if (MaxVal < tmp[i])
			MaxVal = tmp[i];
	}
	if (MaxVal == st1_cnt) {
		answer.push_back(1);
	}
	if (MaxVal == st2_cnt) {
		answer.push_back(2);
	}
	if (MaxVal == st3_cnt) {
		answer.push_back(3);
	}
	sort(answer.begin(), answer.end());
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> input;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		input.push_back(num);
	}
	vector<int> output = solution(input);
	for (int i : output) {
		cout << i << '\n';
	}
	return 0;
}