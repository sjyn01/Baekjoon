#include <iostream>
#include <algorithm>

int n;
int t[16];
int p[16];
int total = 0;
using namespace std;

void calSum(int dsum, int psum) {
	
	if (dsum  >= n+1) {
		total = max(total, psum);
		return;
	}

	if (dsum + t[dsum] <= n + 1) calSum(dsum + t[dsum], psum + p[dsum]);
	// 해당날에 상담을 하고, 해당 상담을 하는데 걸리는 총 일수 만큼 넘어가는 방법
	if (dsum + 1 <= n + 1) calSum(dsum + 1, psum);
	// 해당날에 상담을 하지 않고, 그 다음날로 넘어가는 방법(Day가 + 1만됨)

}
int main() {
	cin >> n;	
	for (int i = 1; i < n+1; i++) {
		cin >> t[i] >> p[i];
	}
	calSum(1, 0);

	cout << total << '\n';

}