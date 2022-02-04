#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][1001];
int ans[1001][1001];
int N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	ans[1][1] = arr[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i == 1 && j == 1) continue;

			ans[i][j] = max(ans[i-1][j-1],max(ans[i-1][j],ans[i][j-1])) + arr[i][j];
		}
	}

	cout << ans[N][M] << '\n';
	return 0;
}