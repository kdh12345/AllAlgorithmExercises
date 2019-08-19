#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



/*string solution(vector<int> numbers) {
	string answer = "";
	string temp = "";
	for (int i = 0; i < numbers.size(); i++) {
		temp += to_string(numbers[i]);
	}
	int zero = 0;//zero갯수
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == '0')
			zero++;
	}
	vector<int> counter;
	for (int i = 0; i < numbers.size(); i++) {
		int cnt = 0;
		int pre = numbers[i];
		while (pre != 0) {
			pre /= 10;
			cnt++;
		}
		counter.push_back(cnt);
	}
	int maxCnt = 0;
	for (int i = 0; i < counter.size(); i++)
	{
		maxCnt = max(counter[i], maxCnt);
	}
	vector<int> copys;//numbers조작 않기 위해 복사본 만듦
	for (int i = 0; i < numbers.size(); i++) {
		copys.push_back(numbers[i]);
	}
	for (int i = 0; i < counter.size(); i++) {
		if (counter[i] != maxCnt) {
			int cnt = counter[i];
			while (cnt != maxCnt) {
				copys[i] *= 10;
				cnt++;
			}
		}
	}
	sort(copys.begin(), copys.end(), greater<int>());
	
	for (int i = 0; i < copys.size(); i++) {

		answer += to_string(copys[i]);
	}
	int copy_zero = 0;
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == '0')
			copy_zero++;
	}
	cout << copy_zero << '\n';
	for (int i = 0; i < answer.size(); i++) {
		if (copy_zero == zero)
			break;
		if (answer[i] == '0') {
			answer[i] = '\0';
		}
		copy_zero--;
	}
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> num;
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		num.push_back(n);
	}
	string ans = solution(num);
	cout << ans << '\n';
	return 0;
}*/
bool cmp(const string& a, const string& b) {
	if (a + b > b + a)
		return true;
	else
		return false;
}
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> str_arr;
	for (int i = 0; i < numbers.size(); i++)
		str_arr.push_back(to_string(numbers[i]));
	sort(str_arr.begin(), str_arr.end(), cmp);
	for (int i = 0; i < str_arr.size();i++) {
		answer += str_arr[i];
	}
	if (answer[0] == '0')//예외처리
		return "0";
	return answer;
}
int main(void) {
	cin.tie(0);
	vector<int> num;
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		num.push_back(n);
	}
	string ans = solution(num);
	cout << ans << '\n';
	return 0;
}