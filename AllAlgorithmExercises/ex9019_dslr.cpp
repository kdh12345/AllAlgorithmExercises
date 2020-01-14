/*

*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
queue<int> q;
int visit[10001];
int dist[10001];//거리 현재는 필요 x
char ch[10001];//다음
int from[10001];
string bfs(int a,int b) {
	visit[a] = 1;
	q.push(a);
	string res = "";
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		int next = (2 * num) % 10000;
		if (!visit[next]) {
			visit[next] = 1;
			q.push(next);
			dist[next] = dist[num] + 1;
			from[next] = num;
			ch[next] = 'D';
		}
		next = num - 1;
		if (next == -1)
			next = 9999;
		if (!visit[next]) {
			visit[next] = 1;
			q.push(next);
			dist[next] = dist[num] + 1;
			from[next] = num;
			ch[next] = 'S';
		}
		next = (num % 1000) * 10 + num / 1000;
		if (!visit[next]) {
			visit[next] = 1;
			q.push(next);
			dist[next] = dist[num] + 1;
			from[next] = num;
			ch[next] = 'L';
		}
		next = (num / 10) + (num % 10) * 1000;
		if (!visit[next]) {
			visit[next] = 1;
			q.push(next);
			dist[next] = dist[num] + 1;
			from[next] = num;
			ch[next] = 'R';
		}
	}
	string ans = "";
	while (a != b) {
		ans += ch[b];
		b = from[b];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b;//a 시작 b 끝
		cin >> a >> b;
		string answer= bfs(a, b);
		cout << answer << '\n';
		memset(visit, 0, sizeof(visit));
		memset(dist, 0, sizeof(dist));
		memset(ch, 0, sizeof(ch));
		memset(from, 0, sizeof(from));
	}

	return 0;
}