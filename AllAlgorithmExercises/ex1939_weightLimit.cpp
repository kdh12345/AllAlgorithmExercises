#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int,int> > conn[100001];
bool visit[100001];
int n, m;
int s, e;
const int Max = 1000000000;
bool bfs(int cost) {
	queue<int> q;
	q.push(s);
	visit[s] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == e) {
			return true;
		}
		for (int i = 0; i < conn[cur].size(); i++) {
			int next = conn[cur][i].first;
			int nextCost = conn[cur][i].second;
			if (visit[next] == false && cost <= nextCost) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		conn[a].push_back(make_pair(b, c));
		conn[b].push_back(make_pair(a, c));;
	}
	cin >> s >> e;
	int left = 0;
	int right = Max;
	while (left <= right) {
		memset(visit, false, sizeof(visit));
		int mid = left + (right - left) / 2;
		if (bfs(mid)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	//최대는 right, 최소는 left
	cout << right << '\n';
	return 0;
}
