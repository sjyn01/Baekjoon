#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N,M;
vector<int> v[32001];
int indegree[32001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		indegree[B]++; //A번 문제는 B보다 먼저!
	}

	priority_queue<int,vector<int>,greater<int>> pq;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int now = pq.top();
		
		pq.pop();

		cout << now << ' ';

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			indegree[next]--;
			if (indegree[next] == 0) pq.push(next);
		}
	}
	cout << '\n';
	return 0;
}