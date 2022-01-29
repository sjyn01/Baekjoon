#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> v, vv;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	vv.push_back(0);
	for (int i = 0; i < N; i++) {
		if (vv.back() < v[i]) {
			vv.push_back(v[i]);
		}
		else {
			int idx = lower_bound(vv.begin(), vv.end(), v[i]) - vv.begin();
			vv[idx] = v[i];
		}
	}
	cout << vv.size() - 1 << '\n';
	return 0;
}