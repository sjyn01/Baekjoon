// 14888 연산자 끼워넣기
// N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.
// 주어진 수의 순서를 바꾸면 안 됨, 식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행

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
	//수의 순서는 바뀌지 않음, 연산자의 순서만
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	//연산자 갯수를 구해서
	//덧셈=0 뺄셈=1 곱셈=2 나눗셈=3 부여

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