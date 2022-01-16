#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
char arr[51][51];
int ans = 65;
string white = "WBWBWBWB";
string black = "BWBWBWBW";

void chk_color(int x, int y) {

	int temp = 0;
	
	for (int i = x; i < x + 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j <8; j++) {
				if (arr[i][y + j] != white[j]) temp++;
			}
		}
		else {
			for (int j = 0; j <8; j++) {
				if (arr[i][y + j] != black[j]) temp++;
			}
		}
	}
	ans = min(ans, temp);

	temp = 0;

	for (int i = x; i < x + 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j <8; j++) {
				if (arr[i][y + j] != black[j]) temp++;
			}
		}
		else {
			for (int j = 0; j <8; j++) {
				if (arr[i][y + j] != white[j]) temp++;
			}
		}
	}
	ans = min(ans, temp);

	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			chk_color(i, j);
		}
	}

	cout << ans << '\n';
	return 0;
}