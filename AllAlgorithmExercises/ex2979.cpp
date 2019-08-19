#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int total = 0;
	int cost[4] = { 0, };
	for (int i = 1; i <= 3; i++) {
		cin >> cost[i];
		cost[i] = i * cost[i];
	}
	int time[101] = { 0, };
	for (int i = 0; i < 3; i++) {
		int arrival, leave;
		cin >> arrival >> leave;
		for (int j = arrival; j < leave; j++)
			time[j]++;
	}
	int len = sizeof(time) / sizeof(int);
	for (int i = 1; i<len; i++)
	{
		total += cost[time[i]];
	}
	cout << total << '\n';
	return 0;
}