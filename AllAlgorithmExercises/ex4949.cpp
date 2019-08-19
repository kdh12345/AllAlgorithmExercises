#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<char> v;
	vector<char> ch;// ) ]
	while (true) {
		bool check = true;
		string s;
		getline(cin, s);
		if (s == ".") {
			break;
		}
		for (unsigned int i = 0; i < s.size(); i++) {
			if (s[i] == '[') {
				v.push_back('[');
			}if (s[i] == '(') {
				v.push_back('(');
			}if (s[i] == ']') {
				ch.push_back(']');
				if (!v.empty()) {
					char c = v.back();
					if (c == '[')
					{
						v.pop_back();
						ch.pop_back();
					}
				}
			}if (s[i] == ')') {
				ch.push_back(')');
				if (!v.empty()) {
					char c = v.back();
					if (c == '(') {
						v.pop_back();
						ch.pop_back();
					}
					
				}
			}
		}
		if (v.empty()&&ch.empty()) {
			cout << "yes" << '\n';
		}
		else
			cout << "no" << '\n';
		v.clear();
		ch.clear();
		
	}
	return 0;
}