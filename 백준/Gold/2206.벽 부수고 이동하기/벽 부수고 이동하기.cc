#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int dist[2][1001][1001];
int arr[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
int flag = -1;

void bfs() {
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{0,0} });
	dist[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int status = q.front().first;

		q.pop();

		if (x == n - 1 && y == m - 1) {
			flag = status;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			int n_status = status;

			if (0 > xx || 0 > yy || xx >= n || yy >= m) continue;

			if (arr[xx][yy] == 1) {
				if (n_status == 1) continue;
				else n_status = 1;
			}

			if (dist[status][xx][yy] != 0) continue;

			q.push({ n_status,{xx,yy} });
			dist[n_status][xx][yy] = dist[status][x][y] + 1;

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	memset(dist, 0, sizeof(dist));
	bfs();

	if (flag == -1) cout << -1 << '\n';
	else cout << dist[flag][n - 1][m - 1] << '\n';

	return 0;
}