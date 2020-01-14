#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int money;
	cin >> money;
	int remain = 1000 - money;
	int hun_five = remain / 500;
	int hun = (remain - hun_five * 500)/100;
	int ten_five = (remain % 100) / 50;
	int ten = (remain % 100) / 10-(ten_five*5);
	int five = (remain % 100) % 10 / 5;
	int one = (remain % 100) % 10 - (five * 5);
	int sum = hun_five + hun + ten_five + ten + five + one;
	cout << sum << '\n';
	return 0;
}