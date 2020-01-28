#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count, num, sum;
int total = 0;

int totalSum(int num) {
	if (num == 0) total += 1;
	if (num - 3 >= 0) totalSum(num - 3);
	if (num - 2 >= 0) totalSum(num - 2);
	if (num - 1 >= 0) totalSum(num - 1);
	return total;
}

int main() {
	
	//NUM이 주어질때 1,2,3중 선택하는 가지수
	scanf("%d", &count);
	while (count--) {
		sum = 0;
		total = 0;
		scanf("%d", &num);
		if (0 < num && num < 11) {
			total = totalSum(num);
			printf("%d\n", total);
		}
	}
}