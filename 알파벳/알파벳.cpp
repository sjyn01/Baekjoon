#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int R, C;
char arr[21][21];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
map<char, int> m;
int ans = 0;

void dfs(int x, int y, int cnt) {

	if (0 > x || 0 > y || x >= R || y >= C || m[arr[x][y]] ) {
		ans = max(ans, cnt);
		return;
	}

	m[arr[x][y]]++;

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		dfs(xx, yy, cnt + 1);	
	}

	m[arr[x][y]]--;
	return;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			arr[i][j] = s[j];
		}
	}

	dfs(0, 0, 0);
	cout << ans << '\n';
	return 0;
}