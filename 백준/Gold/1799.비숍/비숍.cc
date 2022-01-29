#include <iostream>
#include <algorithm>
using namespace std;

int arr[11][11];
int N;
int left_diagonal[21];
int right_diagonal[21];
int ans[2];

void dfs(int x, int y, int cnt, int flag) {

	if (x >= N) {
		ans[flag] = max(ans[flag], cnt);
		return;
	}

	if (y >= N) {
		x++;
		if (y % 2 == 0) y = 1;
		else y = 0;
	}
	
	if (arr[x][y] && left_diagonal[x - y + N - 1] == 0 && right_diagonal[x + y] == 0)
	{
		left_diagonal[x - y + N - 1] = right_diagonal[x + y] = 1;
		dfs(x, y + 2, cnt + 1, flag);
		left_diagonal[x - y + N - 1] = right_diagonal[x + y] = 0;
	}
	dfs(x, y + 2, cnt, flag);
	return;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 0, 0, 0);
	dfs(0, 1, 0, 1);
	cout << ans[0] + ans[1] << '\n';
	return 0;
}