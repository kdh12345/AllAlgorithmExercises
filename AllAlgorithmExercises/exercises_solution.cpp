#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
void borrow_cloth(int arr[], int n) {

	if (arr[n - 1] == 2 || arr[n + 1] == 2) {
		if (arr[n] == 0 && arr[n + 1] == 2) {
			arr[n] = 1;
			arr[n + 1] = 1;
		}else if (arr[n] == 0 && arr[n - 1] == 2) {
			arr[n] = 1;
			arr[n - 1] = 1;
		}
	}
}
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int lost_counter = 0;
	int* arr = new int[n + 2];
	arr[0] = 0; arr[n + 1] = 0;
	for (int i = 1; i <= n; i++)
		arr[i] = 1;
	for (int i = 0;i<lost.size(); i++) {
		arr[lost[i]] -= 1;
	}
	for (int i = 0; i < reserve.size(); i++) {
		arr[reserve[i]] += 1;
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0)
			borrow_cloth(arr, i);
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0)
			lost_counter++;
	}
	answer = n - lost_counter;
	return answer;
}