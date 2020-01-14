#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string assignment) {
	int answer = 0;
	int len = assignment.length();
	stack<char> Stack;
	for (int i = 0; i < len; i++) {
		if (assignment[i] == '(') {
			Stack.push('(');
		}
		else if (assignment[i] == ')') {
			Stack.pop();
			if (assignment[i - 1] == '(') {//·¹ÀÌÀú
				answer += Stack.size();
			}
			else if (assignment[i - 1] == ')') {
				answer++;
			}
		}
	}
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string input;
	cin >> input;
	int ans = solution(input);
	cout << ans << '\n';
	return 0;
}