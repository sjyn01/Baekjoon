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
	// �ش糯�� ����� �ϰ�, �ش� ����� �ϴµ� �ɸ��� �� �ϼ� ��ŭ �Ѿ�� ���
	if (dsum + 1 <= n + 1) calSum(dsum + 1, psum);
	// �ش糯�� ����� ���� �ʰ�, �� �������� �Ѿ�� ���(Day�� + 1����)

}
int main() {
	cin >> n;	
	for (int i = 1; i < n+1; i++) {
		cin >> t[i] >> p[i];
	}
	calSum(1, 0);

	cout << total << '\n';

}