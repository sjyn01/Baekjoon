#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v, arr;
bool chk[9];

void back_tracking(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		v.push_back(arr[i]);
		back_tracking(cnt + 1);
		v.pop_back();
	}
	return;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	back_tracking(0);
}


