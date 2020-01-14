#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

/*string solution(string number, int k) {
	string answer = "";
	vector<int> ind;
	vector<string> ans;
	string tmp = number;
	int m = number.length() - k;
	for (int i = 0; i < m; i++) {
		ind.push_back(1);
	}
	for (int i = 0; i < k; i++) {
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end());
	do {
		string str = "";
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {
				str += tmp[i];
			}
		}
		ans.push_back(str);
	} while (next_permutation(ind.begin(),ind.end()));
	sort(ans.begin(), ans.end());
	answer = ans[ans.size() - 1];
	return answer;
}*/
string solution(string number, int k) {
	string answer = "";
	stack<char> stk;
	int siz = number.length() - k;
	for (int i = 0; i < number.length(); i++) {
		char ch = number[i];
		while (!stk.empty() && k > 0) {
			if (stk.top() >= ch)
				break;
			stk.pop();
			k--;
		}
		stk.push(ch);
	}
	while (stk.size() != siz)
		stk.pop();
	while (!stk.empty()) {
		char x = stk.top();
		answer += x;
		stk.pop();
	}
	reverse(answer.begin(), answer.end());
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin >> k;
	string input;
	cin >> input;
	string out = solution(input, k);
	cout << out << '\n';
	return 0;
}