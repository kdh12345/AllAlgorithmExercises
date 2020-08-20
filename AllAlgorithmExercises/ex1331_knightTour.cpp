#include <iostream>
#include <string>
using namespace std;

//E N W S
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
int arr[6][6];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 36; i++) {
		string word;
		cin >> word;
		int y = (word[0] - 'A') + 1;
		int x = (word[1] - '0');

	}


	return 0;
}