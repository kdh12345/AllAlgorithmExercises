#include <iostream>
#include <string>
using namespace std;
int board[9][9];
int dx[8] = {0,0,1,-1,-1,-1,1,1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string king, stone;
	int	num;//num은 count
	cin >> king >> stone >> num;
	int x, y;// 킹의 위치
	int sx, sy;//돌의 위치
	x = ('8'-king[1]);
	y = (king[0] - 'A');
	sx = ('8'-stone[1]);
	sy = (stone[0] - 'A');
	int nx = 0;
	int ny = 0;
	int snx = 0;
	int sny = 0;
	int dir = 0;
	for (int i = 0; i < num; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "R") {
			
			dir = 0;
		}
		else if (cmd == "L") {
			
			dir = 1;
		}
		else if (cmd == "B") {
			
			dir = 2;
		}
		else if (cmd == "T") {
			
			dir = 3;
		}
		else if (cmd == "RT") {
			
			dir = 4;
		}
		else if (cmd == "LT") {
			
			dir = 5;
		}
		else if (cmd == "RB") {
			
			dir = 6;
		}
		else if (cmd == "LB") {
			
			dir = 7;
		}
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (nx < 0 || nx>=8 || ny < 0 || ny>=8) {
			continue;
		}
		if (nx == sx && ny == sy) {
			snx = sx + dx[dir];
			sny=sy+dy[dir];
			if (snx < 0 || snx>=8 || sny < 0 || sny>=8) {
				continue;
			}
			sx = snx;
			sy = sny;
		}
		x = nx;
		y = ny;
		
	}
	char kingY = (char)y+'A';
	char stoneY = (char)sy+'A';
	x = 8 - x;
	sx = 8 - sx;
	cout << kingY << x << '\n'; 
	cout<<stoneY << sx << '\n';
	return 0;
}