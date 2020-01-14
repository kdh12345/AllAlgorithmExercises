#include <vector>
#include <iostream>
using namespace std;
int check[1000001] = { 0, };
vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i] == arr[i + 1])
		{
			check[i+1] = i+1;
		}
	}
	for (int i = 0; i < arr.size(); i++)
	{
		if (check[i] == 0)
			answer.push_back(arr[i]);
	}
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> input;
	for (int i = 0; i < 7; i++) {
		int num;
		cin >> num;
		input.push_back(num);
	}
	vector<int> output = solution(input);
	for (int i : output) {
		cout << i << ' ';
	}
	cout << '\n';
	return 0;
}