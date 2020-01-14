#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	vector<int> tmp = prices;
	int len = tmp.size();
	for (int i = 0; i < len; i++) {
		int count = 0;
		for (int j = i; j < len; j++) {
			if (tmp[i] > tmp[j] || j == len - 1) {
				answer.push_back(count);
				break;
			}
			else {
				count++;
			}
			
		}
		
	}
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> price(5);
	for (int i = 0; i < 5; i++) {
		cin >> price[i];
	}
	vector<int> ans = solution(price);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';


	return 0;
}