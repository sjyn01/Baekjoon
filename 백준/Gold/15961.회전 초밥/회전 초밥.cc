#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, d, k, c;
int arr[3000001];
int chk[3001];
int ans = 0;

int main() {
	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < k; i++) {
		chk[arr[i]]++;
		if (chk[arr[i]] == 1) ans++;
	}

	int temp = ans;

	for (int i = 0; i < N - 1; i++) {
		chk[arr[i]]--;
		if (chk[arr[i]] == 0) temp--;

		chk[arr[(i + k) % N]]++;
		if (chk[arr[(i + k) % N]] == 1) temp++;

		if (chk[c]) ans = max(ans, temp);
		else ans = max(ans, temp + 1);
	}

	cout << ans << '\n';
	return 0;
}