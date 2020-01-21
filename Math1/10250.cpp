#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*int main() {
	//h 층수 w 각층방수 n 몇번째 손님
	//N-h-h.... 그 값이 0보다 작아질때 그 수에다가 남은 수를 더해준다
	int h, w, n;
	int num;
	int count, floor;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		count = 0;
		scanf("%d %d %d", &h, &w, &n);
		while (1) {
			count++;
			if (n - h <= 0) break;
			else n = n - h;
		}
		floor = 100 * n + count;
		printf("%d\n", floor);
	}
	return 0;
}*/
int main() {
	int h, w, n;
	int num;
	scanf("%d", &num);
	while (num--) {
		scanf("%d %d %d", &h, &w, &n);
		printf("%d%02d\n", ((n - 1) % h) + 1, (n - 1) / h + 1);// n/h를 나눴을때 딱 떨어지는 경우 ex>30층 90번째손님은 330호일것
	}
	return 0;
}