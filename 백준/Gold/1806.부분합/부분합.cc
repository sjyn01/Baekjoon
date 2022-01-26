#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 987654321
using namespace std;

int N, S;
vector<int> arr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;
	arr.resize(N);
	for (int i = 0; i < N; i++) cin >> arr[i];

	int start = 0;
	int end = 0;
	int sum = 0;
	int ans = MAX;
	while (start <= end && end <= N) {
	
		if (sum < S) {
			sum += arr[end++];
		}
		else {
			ans = min(ans, end - start);
			sum -= arr[start++];
		}

	}
	if (ans == MAX) cout << 0 << '\n';
	else cout << ans << '\n';
	return 0;
}