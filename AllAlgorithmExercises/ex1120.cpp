#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a, b;
	cin >> a >> b;// �������� ����
	int ans = 51;//max ���� 50
	//���ĺ��߰��� �ִ��Ѱ��� ���Ѵ��� a�� ���ڸ��� b�� ���ڸ��� �ش��ϴ� ���ĺ����� ä���.(����)
	for (int dis = 0; dis <= b.length() - a.length(); dis++) {
		int cnt = 0;//�ٸ��� ����
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[dis + i])
				cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}