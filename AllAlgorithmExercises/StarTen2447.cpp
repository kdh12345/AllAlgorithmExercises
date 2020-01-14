#include <iostream>
#include <cstring>
using namespace std;
//ó���� ���� ���� �������� ��Ģ�� ã���� ������ �̰��� �߸��� ���ٹ���̶����� �˰Ե�
//��������
//27*27->9*9 �̷������� �ɰ��� �ٽ� ������
//�ɰ��� ���� ��Ģ�� ���´�. ���� ���°� ������ ���ļ� �ϳ��� ���°� ��
char matrix[2200][2200];
void Star(int a,int b,int end) {
	if (end == 1) {
		matrix[a][b] = '*';
		return;
	}
	int num = end / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;//���
			else {
				//matrix[i][j] = '*';
				Star(a + i * num, b + j * num, end/3);
			}
				
		}

	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	memset(matrix, ' ', sizeof(matrix));
	Star(0,0,n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j];
		}
		cout << '\n';
	}
	return 0;
}