/*N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 
그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.*/
#include <iostream>
#include <algorithm>

using namespace std;
int arr[20];
int n, s, ans = 0;

void sumCount(int sum, int idx, int leng) {
	sum += arr[idx];

	if (idx >= n)
		return;

	if (sum == s && leng >= 1)
		ans++;

	sumCount(sum, idx + 1, leng + 1);//현 인덱스 값을 더했을 때
	sumCount(sum - arr[idx], idx + 1, leng);//현 인덱스 값을 더하지 않았을 때
}



int main() {

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; // 입력을 받아서 배열에 넣어줌
	}

	sumCount(0,0,1); //부분 수열 갯수 출력
	cout << ans << '\n';

	return 0;
}