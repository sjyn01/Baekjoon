#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, S;
int half;
map<int, int> m;
vector<int> v;
long long ans = 0;

//이 문제는 N의 범위가 40까지이기 때문에 단순하게 dfs로 풀경우
//O(2^N)을 할 경우 시간초과가 난다
//분할 정복으로 나눠서 생각해 푼다 O(2^(N/2))
void dfs_left(int idx, int sum) {
	if (idx == half) {
		m[sum]++;
		return;
	}

	dfs_left(idx + 1, sum + v[idx]);
	dfs_left(idx + 1, sum);
}

void dfs_right(int idx, int sum) {
	if (idx == N) {
		ans += m[S - sum]; // 오른쪽 부분수열의 합(sum) + 왼쪽 부분수열의 합(m[S-sum]) = S
		return;
	}
	dfs_right(idx + 1, sum);
	dfs_right(idx + 1, sum + v[idx]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;
	
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	half = v.size() / 2;

	dfs_left(0, 0);

	dfs_right(half, 0);

	if (S == 0) cout << ans - 1 << '\n'; 
	//S가 0인 경우는 공집합인 경우가 있다
	//크기가 양수인 부분수열이기 때문에 하나 빼준다
	else cout << ans << '\n';
	return 0;
}