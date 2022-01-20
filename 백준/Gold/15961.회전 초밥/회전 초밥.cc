#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <unordered_set>
#include <map> 
#include <algorithm>
#include <cmath>
#include <ctime>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ENDL cout << endl
#define ll long long
#define ull unsigned long long
#define INF 987654321
#define Mod 1000000007
#define endl '\n'

using namespace std;

int N, d, k, c;
vector<int> ps;
int visited[30001];

void input() {
	cin >> N >> d >> k >> c;
	ps = vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> ps[i];
	}
}

int solution() {
	int cnt = 0;
	int answer;
	for (int left = 0; left < k; left++) {
		if (!visited[ps[left]]) {
			cnt++;
		}
		visited[ps[left]]++;
	}
	if (visited[c] == 0) answer = cnt + 1;
	else answer = cnt;

	int left = 0, right = k-1;
	while (1) {
		// 가장 왼쪽에 있던 초밥을 제거
		visited[ps[left]]--;
		if(visited[ps[left]]==0) cnt--;
		// 가장 왼쪽이 마지막 위치까지 올 경우 모든 구간 확인 
		left++;
		if (left == N) break;
		// 오른쪽으로 이동 -> 마지막까지 이동했으면 0부터 다시 확인
		right++;
		if (right == N) right = 0;
		if (visited[ps[right]] == 0) cnt++;
		visited[ps[right]]++;

		if (visited[c] == 0) answer = max(answer, cnt + 1);
		else answer = max(answer, cnt);
	}
	return answer;
}

int main() {
	fastio;
	input();
	cout << solution();

	return 0;
}