#include <iostream>
using namespace std;

void alarm_control(int hr, int min) {
	if (hr == 0) {
		hr = 24;
	}
	if (min < 45) {
		hr -= 1;
		min += 60;
		min -= 45;
	}
	else {
		min -= 45;
	}
	cout << hr << ' ' << min << '\n';
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int hour, minute;
	cin >> hour >> minute;
	alarm_control(hour, minute);
	return 0;
}