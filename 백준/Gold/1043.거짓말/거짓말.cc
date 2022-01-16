#include <iostream>
#include <vector>
using namespace std;

int n, m, p;
int idx, ans;
int Parent[51];
vector<int> know_truth;
vector<int> party[51];

int Find_Parent(int X) {
	if (X == Parent[X]) return X;
	return Parent[X] = Find_Parent(Parent[X]);
}

void Union(int A, int B) {
	A = Find_Parent(A);
	B = Find_Parent(B);
	Parent[B] = A;
}

int main() {
	cin >> n >> m;
	cin >> p;

	for (int i = 0; i < p; i++) { //진실을 아는사람 체크
		cin >> idx;
		know_truth.push_back(idx);
	}

	for (int i = 0; i < m; i++) { //파티 수만큼 확인
		cin >> p;
		for (int j = 0; j < p; j++) {
			cin >> idx;
			party[i].push_back(idx);
		}
	}

	for (int i = 1; i <= n; i++) Parent[i] = i;
	
	for (int i = 0; i < m; i++) {
		int n1 = party[i][0];
		for (int j = 1; j < party[i].size(); j++) {
			int n2 = party[i][j];
			Union(n1, n2);
		}
	}

	for (int i = 0; i < m; i++) {
		bool flag = false;
		for (int j = 0; j < party[i].size(); j++) {
			int n1 = party[i][j];
			for (int k = 0; k < know_truth.size(); k++) {
				if (Find_Parent(n1) == Find_Parent(know_truth[k])) {
					flag = true;
					break;
				}
			}
			if (flag) break;
		}

		if (!flag) ans++;
	}

	cout << ans << '\n';
	return 0;
}