#include <iostream>
#include <queue>

using namespace std;

int n, k;

queue<int> q;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) q.push(i);

	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}

		cout << q.front();
		q.pop();
		if (q.size()) cout << ", ";
		else cout << ">\n";
	}
	return 0;
}