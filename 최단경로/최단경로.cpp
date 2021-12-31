#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 987654321

using namespace std;

int V, E, K;
vector<pair<int, int>> arr[20001];
int dist[20001];
bool visit[20001];

void dijkstra(int start) {

	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		if (visit[now]) continue;
		visit[now] = true;

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
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		arr[u].push_back({ v,w });
	}

	for (int i = 1; i <= V; i++) dist[i] = MAX;
		

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (i == K) cout << 0 << '\n';
		else if (dist[i] == MAX) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
	return 0;
}