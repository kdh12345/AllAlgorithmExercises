#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
bool visited[31][31][31];
char graph[31][31][31];

/*
3���� bfs������ queue<pair<pair<int, int>, pair<int, int>> > q;
�� �̿��ؼ� Ƚ��, l,r,c�� ��� �������
2���������� Ƚ�� , r,c ��� �������
queue<pair<int,pair<int,int> >q;
*/
int l, r, c;
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dh[6] = { 0,0,0,0,-1,1 };
int l_exit;
int x_exit;
int y_exit;
struct building {
	int cnt, high, x, y;
};
int bfs(int floor, int a, int b) {
	//struct building build;
	queue<building> q;//������ �� ��ĭ ���� �߿�!!!
	int cnt = 0;
	visited[floor][a][b] = true;
	q.push({ cnt,floor,a,b });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int f = q.front().high;
		cnt = q.front().cnt;
		q.pop();
		if (f == l_exit && x == x_exit && y == y_exit) {
			return cnt;
		}
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int high = f + dh[i];
			
			if (1 <= nx && nx <= r && 1 <= ny && ny <= c) {
				if (1 <= high && high <= l) {
					if (graph[high][nx][ny] == '#') {
						//visited[high][nx][ny] = true;
						continue;
					}
					if (graph[high][nx][ny] == '.' ||graph[high][nx][ny] == 'E') {
						if (!visited[high][nx][ny]) {
							visited[high][nx][ny] = true;
							//make_pair(make_pair(cnt+1,high), make_pair(nx, ny))
							q.push({ cnt + 1,high,nx,ny });
						}
					}

				}
			}
		}//i	

	}
	return -1;//0�� �信 ���ԵǹǷ�
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		memset(visited, false, sizeof(visited));
		memset(graph, 0, sizeof(graph));
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)// l�� r ���� c ����
			break;
		//�ʱ�ȭ
		l_exit = 0;
		x_exit = 0;
		y_exit = 0;
		//i j k
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				for (int k = 1; k <= c; k++) {
					cin >> graph[i][j][k];
				}
			}
		}//i
		//bool isS = false;
		int s1 = 0;
		int s2 = 0;
		int s3 = 0;
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				for (int k = 1; k <= c; k++) {
					if (graph[i][j][k] == 'S')
					{
						s1 = i;
						s2 = j;
						s3 = k;
					}
					else if (graph[i][j][k] == 'E') {
						l_exit = i;
						x_exit = j;
						y_exit = k;
					}
				}//k
				
			}//j
		
		}//i
		int ans=bfs(s1, s2, s3);//s1 s2 s3 ������
		if (ans==-1) {
			cout << "Trapped!" << '\n';
		}
		else
		{
			cout << "Escaped in" << ' ' << ans << ' ' << "minute(s)." << '\n';
		}
	}
	return 0;
}