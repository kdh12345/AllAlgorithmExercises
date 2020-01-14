#include <iostream>
#include <stack>
using namespace std;

int arr[1000];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int Min = 1000;
	int idx = 0;
	for (int i = 0; i < 10; i++) {
		if (Min > arr[i])
		{
			Min = arr[i];
			idx = i;
		}
	}
	stack<int> st;
	for (int i = idx; i < n; i++) {
		if (st.top() < arr[i])
		{
			st.push(arr[i]);
		}
		else
			st.pop();
	}
	cout << st.size() << '\n';

	return 0;
}
