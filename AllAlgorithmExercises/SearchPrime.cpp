#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int check[10000000];
int solution(string numbers) {
	int answer = 0;
	int len = numbers.length();
	sort(numbers.begin(), numbers.end());
	for (int i = 2; i <= len; i++) {
		int ans = select(numbers,0,i);
	}
	return answer;
}
int select(string numbers, int cnt,int m) {
	vector<int> v;
	vector<int> output;
	if (cnt == m) {
		int num = 0;
		int mul = 1;
		for (int i = output.size()-1; i >0; i--) {
			num = output[i] * mul;
			mul =
		}
	}
	for (int i = 0; i < numbers.length(); i++) {
		int num = numbers[i] - '0';
		v.push_back(num);
	}
	int len = v.size();
	for (int i = 0; i < len; i++) {
		if (check[v[i]])
			continue;
		check[v[i]] = true;
		output.push_back(v[i]);
		select(numbers, cnt + 1, m);
		output.pop_back();
		check[v[i]] = false;
	}
}