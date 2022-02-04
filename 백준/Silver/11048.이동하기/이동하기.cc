#include <iostream>
#include <algorithm>
using namespace std;

int ans[1001][1001];
int N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int num;
			cin >> num;
			ans[i][j] = max(ans[i - 1][j - 1], max(ans[i - 1][j], ans[i][j - 1])) + num;
		}
	}
	cout << ans[N][M] << '\n';
	return 0;
}
