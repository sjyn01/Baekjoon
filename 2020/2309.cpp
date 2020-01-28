//아홉 개의 줄에 걸쳐 난쟁이들의 키가 주어진다. 주어지는 키는 100을 넘지 않는 자연수이며, 
//아홉 난쟁이의 키는 모두 다르며, 가능한 정답이 여러 가지인 경우에는 아무거나 출력한다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NUM 9

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void quickSort(int left, int right, int* data) {
	int pivot = left;
	int j = pivot;
	int i = left + 1;

	if (left < right) {
		for (; i <= right; i++) {
			if (data[i] < data[pivot]) {
				j++;
				swap(&data[j], &data[i]);
			}
		}
		swap(&data[left], &data[j]);
		pivot = j;

		quickSort(left, pivot - 1, data);
		quickSort(pivot + 1, right, data);
	}

}

int main() {

	int num[MAX_NUM];
	int check[MAX_NUM];
	int total=0, max=0, flag=0;
	for (int i = 0; i < MAX_NUM; i++) {
		scanf("%d", &num[i]);
		total += num[i];
		check[i] = 0;
	}
	max = total - 100;
	//오름차순 정렬 sorting
	quickSort(0, MAX_NUM - 1, num);

	//1부터 하나씩 더하다가 값을 넘어가면 뒤로 돌아옴  total += num[i] total=100이면 정답 total<100이면 반복해서 더함
	//total>100이면 두번째부터 시작
	//원래 없던 2명의 난쟁이 키의 합 = 전체 난쟁이 9명의 키 - 100  ( 9C2 == 9C7)

	for (int i = 0; i < MAX_NUM; i++) {
		for (int j = i + 1; j < MAX_NUM; j++) {
			if (num[i] + num[j] == max) {
				check[i] = check[j] = 1;
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}
	for (int i = 0; i < MAX_NUM; i++) {
		if (!check[i]) { printf("%d\n", num[i]); }
	}

	return 0;
}