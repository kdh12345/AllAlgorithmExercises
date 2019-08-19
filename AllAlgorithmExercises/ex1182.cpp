#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> arr;
int n, s;
vector<int> output;
bool check[21];
vector<int> ans;
void get_part(int start,int end_num,int m) {
	if (end_num == m+1) {
		int sum = 0;
		for (unsigned int i = 0; i < output.size(); i++) {
			sum += output[i];
		}
		ans.push_back(sum);
		return;
	}
	
	for (int i = start; i <n; i++)
	{
		if (check[i])
			continue;
		check[i] = true;
		output.push_back(arr[i]);
		get_part(i, end_num+1,m);
		check[i] = false;
		output.pop_back();
	}	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}
	int cnt = 0;
	sort(arr.begin(), arr.end());
	for (unsigned int i = 0; i < n; i++) {
		if (arr[i] == s)
			cnt++;
	}
	int m = 1;
	for(int i=m;i<n;i++)
		get_part(0,0,i);
	
	for (unsigned int i = 0; i < ans.size(); i++)
	{
		if (ans[i] == s)
			cnt++;

	}
	cout << cnt << '\n';
	return 0;
}