#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int w, h, T;
char arr[1001][1001];
bool chk[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> T;
	while (T--) {
		queue<pair<int, int>> human, fire;
		bool flag = false;
		int cnt = 0;
		memset(chk, false, sizeof(chk));

		cin >> h >> w;
		for (int i = 0; i < w; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < h; j++) {
				arr[i][j] = s[j];
				if (arr[i][j] == '@') human.push({ i,j }); // 상근이 위치 저장
				else if (arr[i][j] == '*') fire.push({ i,j }); // 불 위치 저장
			}
		}

		while (!human.empty()) {
			int f_size = fire.size();

			for (int i = 0; i < f_size; i++) {
				int x = fire.front().first;
				int y = fire.front().second;

				fire.pop();

				for (int k = 0; k < 4; k++) {
					int xx = x + dx[k];
					int yy = y + dy[k];

					if (0 > xx || 0 > yy || xx >= w || yy >= h) continue;
					//이동 불가능한 조건 제거
					if (arr[xx][yy] == '.') {
						arr[xx][yy] = '*';
						fire.push({ xx,yy });
					}
				}
			}

			int h_size = human.size();
			for (int i = 0; i < h_size; i++) {
				int x = human.front().first;
				int y = human.front().second;

				human.pop();

				if (x == 0 || y == 0 || x == w - 1 || y == h - 1) {
					flag = true;
					break;
				}

				for (int k = 0; k < 4; k++) {
					int xx = x + dx[k];
					int yy = y + dy[k];

					if (0 > xx || 0 > yy || xx >= w || yy >= h) continue;
					//이동 불가능한 조건 제거
					if (chk[xx][yy] == false && arr[xx][yy] == '.') {
						chk[xx][yy] = true;
						human.push({ xx,yy });
					}
				}
			}
			if (flag) break;
			cnt++;
		}
		if (flag) cout << cnt + 1 << '\n';
		else cout << "IMPOSSIBLE\n";
	}
	return 0;
}