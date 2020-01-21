// 14888 ������ �����ֱ�
// N���� ���� N-1���� �����ڰ� �־����� ��, ���� �� �ִ� ���� ����� �ִ��� �Ͱ� �ּ��� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// �־��� ���� ������ �ٲٸ� �� ��, ���� ����� ������ �켱 ������ �����ϰ� �տ������� ����

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_NUM 11
#define MAX_SUM -1000000001
#define MIN_SUM 1000000001
using namespace std;

int main() {
	int num;
	int arr[MAX_NUM];
	int brr[MAX_NUM - 1];
	int temp, onum = 0;
	int index = 0;
	int smax = MAX_SUM, smin = MIN_SUM;
	//���� ������ �ٲ��� ����, �������� ������
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	//������ ������ ���ؼ�
	//����=0 ����=1 ����=2 ������=3 �ο�

	for (int j = 0; j < 4; j++) {
		cin >> temp;
		for (int i = onum; i < onum + temp; i++) {
			brr[i] = index;
		}
		index++;
		onum += temp;
	}

	do {
		int sum = arr[0];
		for (int i = 1; i < num; i++) {
			switch (brr[i - 1]) {
			case 0:
				sum += arr[i];
				break;
			case 1:
				sum -= arr[i];
				break;
			case 2:
				sum *= arr[i];
				break;
			case 3:
				if (sum < 0) {
					sum = (-sum) / arr[i];
					sum = (-sum);
				}
				else sum /= arr[i];
				break;
			}
		}
		smin = min(smin, sum);
		smax = max(smax, sum);
	} while (next_permutation(brr, brr + onum));

	cout << smax << '\n';
	cout << smin << '\n';

	return 0;
}