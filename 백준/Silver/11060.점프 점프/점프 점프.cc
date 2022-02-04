#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 987654321
using namespace std;
int ans[1101];
int N;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) ans[i] = MAX;
	ans[1] = 0;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		for(int j=1; j<=num; j++) ans[i + j] = min(ans[i + j], ans[i] + 1);
	}
	if (ans[N] == MAX) cout << -1 << '\n';
	else cout << ans[N] << '\n';
	return 0;
}