#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define MAX 987654321
using namespace std;

int n, m;
int first, last;
vector<pii> arr[1001];
bool chk[1001];
int dist[1001];

void dijkstra(int start) {

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		if (chk[now]) continue;
		chk[now] = true;

		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int val = arr[now][i].second;

			if (dist[next] > dist[now] + val) {
				dist[next] = dist[now] + val;
				pq.push({ dist[next],next });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
	}
	cin >> first >> last;

	for (int i = 1; i <= n; i++) dist[i] = MAX;
	dijkstra(first);

	cout << dist[last] << '\n';
	return 0;
}
