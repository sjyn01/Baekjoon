#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
bool chk[9];

void back_tracking(int now, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = now; i <= N; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		v.push_back(i);
		back_tracking(i+1, cnt + 1);
		v.pop_back();
		chk[i] = false;
	}
	return;
}
int main() {
	cin >> N >> M;
	back_tracking(1,0);
}