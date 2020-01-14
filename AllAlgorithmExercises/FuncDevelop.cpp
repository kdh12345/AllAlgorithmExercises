#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> f;
	int arr[100] = { 0, };
	for (int i = 0; i < progresses.size(); i++) {
		int day = 0;
		while (progresses[i] < 100) {
			progresses[i] += speeds[i];
			day++;
		}
		f.push_back(day);
	}
	for (int i = 0; i < f.size() - 1; i++) {
		if (f[i] > f[i + 1])
		{
			f[i + 1] = f[i];
		}
	}
	for (int i = 0; i < f.size(); i++) {
		arr[f[i]]++;
		//cout << f[i] << ' ';
	}
	int tmp = 0;
	for (int i = 0; i < f.size(); i++)
	{
		if(tmp!=arr[f[i]])
			answer.push_back(arr[f[i]]);
		tmp = arr[f[i]];
	}
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> pr;//진행
	vector<int> sp;//스피드
	for (int i = 0; i < 6; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		pr.push_back(n1);
		sp.push_back(n2);
	}
	vector<int> out = solution(pr, sp);
	for (int i : out) {
		cout << i << '\n';
	}
	return 0;
}