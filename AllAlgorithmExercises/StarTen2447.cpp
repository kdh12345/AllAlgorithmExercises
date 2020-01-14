#include <iostream>
#include <cstring>
using namespace std;
//처음에 라인 바이 라인으로 규칙을 찾으려 했으나 이것은 잘못된 접근방식이란것을 알게됨
//분할정복
//27*27->9*9 이런식으로 쪼개서 다시 합하자
//쪼개서 보자 규칙이 나온다. 같은 형태가 여러개 합쳐서 하나의 형태가 됨
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
				continue;//가운데
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