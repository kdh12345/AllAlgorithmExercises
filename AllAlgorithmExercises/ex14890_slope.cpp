#include <iostream>
using namespace std;
int n, l;
int ans;
int map[201][101];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			map[n + y][x] = map[x][y];//�������� �����ٷ� ������ �ؿ� ����
		}
	}
	int count = 0;
	int j = 0;
	for (int i = 0; i < 2 * n; i++) {
		count = 1;
		for (j = 0; j < n - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {//����
				count++;
			}
			
			else if (map[i][j] - 1 == map[i][j + 1] && count >= 0) {//������
				count = 1-l;
			}
			else if (map[i][j] + 1 == map[i][j + 1] && count >= l) {//������
				count = l;
			}
			else {
				break;//�ƹ��͵� �ƴϸ� ���� �� ����
			}
		}
		if (j == n - 1 && count >= 0) {//�����ִ� ���
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}