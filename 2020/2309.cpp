//��ȩ ���� �ٿ� ���� �����̵��� Ű�� �־�����. �־����� Ű�� 100�� ���� �ʴ� �ڿ����̸�, 
//��ȩ �������� Ű�� ��� �ٸ���, ������ ������ ���� ������ ��쿡�� �ƹ��ų� ����Ѵ�.

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
	//�������� ���� sorting
	quickSort(0, MAX_NUM - 1, num);

	//1���� �ϳ��� ���ϴٰ� ���� �Ѿ�� �ڷ� ���ƿ�  total += num[i] total=100�̸� ���� total<100�̸� �ݺ��ؼ� ����
	//total>100�̸� �ι�°���� ����
	//���� ���� 2���� ������ Ű�� �� = ��ü ������ 9���� Ű - 100  ( 9C2 == 9C7)

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