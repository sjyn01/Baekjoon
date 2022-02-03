#include <iostream>
#include <algorithm>
using namespace std;

int arr[11][11];
bool chk[11][11];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int N, M, K;
int ans = -2e9;

void back_tracking(int cnt, int sum) {


	if (cnt == K) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			bool flag = false;
			if (chk[i][j]) continue;
			for (int k = 0; k < 4; k++) {
				int xx = i + dx[k];
				int yy = j + dy[k];
				if (0 > xx || 0 > yy || xx >= N || yy >= M) continue;
				if (chk[xx][yy]) flag = true;
			}
			if (!flag) {
				chk[i][j] = true;
				back_tracking(cnt + 1, sum + arr[i][j]);
				chk[i][j] = false;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	back_tracking(0, 0);
	cout << ans << '\n';
	return 0;
}