#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	sort(lost.begin(), lost.end());//도난당한학생
	vector<int> student;
	for (int i = 0; i < lost.size(); i++) {
			student.push_back(lost[i]);
	}
	sort(reserve.begin(), reserve.end());//여벌이 있는 학생
	vector<int> result;
	int notVal= 0;
	for (int i = 0; i < student.size(); i++) {
		for (int j = i; j < reserve.size(); j++) {
			if (student[i] == reserve[j])
				continue;
			if (reserve[j] - 1 == student[i] || reserve[j] + 1 == student[i]) {
				result.push_back(student[i]);
				break;
			}
		}
	}
	for (int i = 0; i < reserve.size(); i++)
		result.push_back(reserve[i]);
	answer = result.size()+answer;
	return answer;
}
int main(void) {
	int n;
	cin >> n;
	vector<int> lost;
	vector<int> reserve;
	for (int i = 0; i < 2; i++)
	{
		int num;
		cin >> num;
		lost.push_back(num);
	}
	for (int i = 0; i < 3; i++)
	{
		int num;
		cin >> num;
		reserve.push_back(num);
	}
	int ans=solution(n, lost, reserve);
	cout << ans;
	return 0;
}