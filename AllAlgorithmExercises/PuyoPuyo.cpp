#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int cnt;
queue<pair<int, int> > q;
char board[13][7];
bool visit[13][7] = { false, };
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
//����Ȯ�νÿ��� q�� �ϳ��� �����ؼ� �䱸�ϴ� ũ�⸸ŭ�� ����ִ��� Ȯ���� ���ݴϴ�.
int bfs() {
	while (1) {
		vector<pair<int, int> > v;
		memset(visit, false, sizeof(visit));
		for (int x = 0; x < 11; x++) {
			for (int y = 0; y < 6; y++) {
				if (board[x][y] == '.') {
					continue;
				}
				queue<pair<int, int> > popped_color;//���� ������ puyo�� �����¿쿡 4���ִ��� Ȯ��
				char color = board[x][y];
				visit[x][y] = true;
				q.push(make_pair(x, y));
				while (!q.empty()) {
					int CurX = q.front().first;
					int CurY = q.front().second;
					popped_color.push(make_pair(CurX, CurY));
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = CurX + dx[i];
						int ny = CurY + dy[i];
						if (0 <= nx && nx < 12 && 0 <= ny && ny < 6) {
							if (board[nx][ny] == color && !visit[nx][ny]) {
								visit[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
						}
					}//i ����ȸ��
				}//not empty
				if (popped_color.size() >= 4) {
					while (!popped_color.empty()) {
						v.push_back(make_pair(popped_color.front().first, popped_color.front().second));
						popped_color.pop();
					}
				}//���� Ȯ��
			}
		}
		if (v.size() > 0) {
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size(); i++) {
				for (int j = v[i].first; j > 0; j--) {
					board[j][v[i].second] = board[j - 1][v[i].second];
				}
				board[0][v[i].second] = '.';
			}
			cnt++;
		}
		else
			break;
	}
	return cnt;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}
	int ans = bfs();
	cout << ans << '\n';
	return 0;
}