#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*int main() {
	//h ���� w ������� n ���° �մ�
	//N-h-h.... �� ���� 0���� �۾����� �� �����ٰ� ���� ���� �����ش�
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
		printf("%d%02d\n", ((n - 1) % h) + 1, (n - 1) / h + 1);// n/h�� �������� �� �������� ��� ex>30�� 90��°�մ��� 330ȣ�ϰ�
	}
	return 0;
}