/*N���� ������ �̷���� ������ ���� ��, ũ�Ⱑ ����� �κм��� �߿��� 
�� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.*/
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

	sumCount(sum, idx + 1, leng + 1);//�� �ε��� ���� ������ ��
	sumCount(sum - arr[idx], idx + 1, leng);//�� �ε��� ���� ������ �ʾ��� ��
}



int main() {

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; // �Է��� �޾Ƽ� �迭�� �־���
	}

	sumCount(0,0,1); //�κ� ���� ���� ���
	cout << ans << '\n';

	return 0;
}