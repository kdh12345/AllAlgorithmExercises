#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int index[101] = { 0, };
	string word;
	getline(cin, word);
	sort(word.begin(), word.end());
	for (int i = 0; i < word.size(); i++) {
		index[word[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << index[i] << ' ';
	}
	return 0;
}
