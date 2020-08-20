#include <iostream>
#include <string>
using namespace std;

/// <summary>
///  JOI의 개수, 둘째 줄에 IOI의 개수
/// </summary>
/// <param name=""></param>
/// <returns></returns>
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string word;
	cin >> word;
	int jCnt = 0;
	int iCnt = 0;
	for (int i = 0; i < word.length(); i++) {
		string cmp = word.substr(i, 3);
		if (cmp == "JOI") {
			jCnt++;
		}
		if (cmp == "IOI") {
			iCnt++;
		}
	}
	cout << jCnt << '\n';
	cout << iCnt << '\n';

	return 0;
}