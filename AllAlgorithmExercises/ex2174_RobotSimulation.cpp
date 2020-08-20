#include <iostream>
#include <vector>
using namespace std;

struct robot {
	int X;
	int Y;
	int dir;
};
vector<robot> v(101);
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int board[101][101];
int a, b;
bool go(int index, char cmd, int cnt) {
	int& x = v[index].X;
	int& y = v[index].Y;
	int& dirs = v[index].dir;
	board[x][y] = 0;
	while (cnt--) {
		if (cmd == 'R') {
			dirs = (dirs + 3) % 4;
		}
		else if (cmd == 'L') {
			dirs = (dirs + 1) % 4;
		}
		else if (cmd == 'F') {
			x += dx[dirs];
			y += dy[dirs];
			
			if (x<1 || x>b || y<1 || y>a) {//¹Ù±ùÀ¸·Î ¹þ¾î³ª¸é
				printf("Robot %d crashes into the wall\n", index);
				return true;
			}
			if (board[x][y]) {//Ãæµ¹
				printf("Robot %d crashes into robot %d\n", index, board[x][y]);
				return true;
			}
		}
		
	}
	board[x][y] = index;
	return false;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x, y;
		char direction;
		cin >> x >> y >> direction;
		if (direction == 'E') {
			direction = 0;
		}
		else if (direction == 'N') {
			direction = 1;
		}
		else if (direction == 'W') {
			direction = 2;
		}
		else if (direction == 'S') {
			direction = 3;
		}
		v[i] = { y,x,direction };
		board[y][x] = i;
	}
	bool flag = false;
	for (int i = 0; i < m; i++) {
		int id, cnt;
		char ch;
		cin >> id >> ch >> cnt;
		if (!flag)
			flag = go(id, ch, cnt);
	}
	if (!flag)
		cout << "OK" << '\n';
	return 0;
}