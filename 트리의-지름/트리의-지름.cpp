#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int v;
vector<pair<int, int>> arr[100001];
bool chk[100001];
int ans = 0;
int ans_idx = 0;

void dfs(int idx, int sum) {
	if (chk[idx]) return;

	chk[idx] = true;

	if (ans < sum) {
		ans = sum;
		ans_idx = idx;
	}

	for (int i = 0; i < arr[idx].size(); i++) {
		dfs(arr[idx][i].first, sum + arr[idx][i].second);
	}
}
int main() {

	//임의의 두점 사이의 거리 중 가장 긴 것이기 때문에 플로이드-와샬 x

	//임의의 정점 a로부터 가장 먼 정점 b를 찾는다
	//b로부터 가장 먼 정점 c를 찾는다
	//b와 c를 연결하는 경로가 트리의 지름이다

	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 실행속도 향상

	cin >> v;

	for (int i = 0; i < v; i++) {
		int node; 
		cin >> node;

		while (1) {
			int idx, val;
			cin >> idx;
			if (idx == -1) break;
			cin >> val;
			arr[node].push_back({ idx,val });
		}
	}

	dfs(1, 0);

	memset(chk, false, sizeof(chk));
	ans = 0;

	dfs(ans_idx, 0);

	cout << ans << '\n';
	
	return 0;
}