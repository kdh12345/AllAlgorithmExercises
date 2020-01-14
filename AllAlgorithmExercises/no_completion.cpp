#include <string>
#include <vector>
#include <map>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	completion.push_back("");
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	map<string, string> par;
	
	for (int i = 0; i < completion.size(); i++) {
		par.insert(make_pair(participant[i], completion[i]));
	}
	map<string, string>::iterator it;
	for (it = par.begin(); it != par.end(); it++) {
		cout << it->first << ' ' << it->second << '\n';
		if (it->first != it->second)
			answer = it->first;
	}
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<string> p;
	vector<string> c;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		p.push_back(name);
	}
	for (int i = 0; i < n - 1; i++) {
		string name;
		cin >> name;
		c.push_back(name);
	}
	cout << solution(p, c) << '\n';
	return 0;
}