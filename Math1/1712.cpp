#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;
	//�� �����(i) * ����(c) >= �������(a) + �� �����(i) * �������(b)
	scanf("%d %d %d", &a, &b, &c);
	int x = c - b;
	if (x <= 0) printf("-1\n");//��������� �� ũ�� ������ �߻� x
	else {
		printf("%d", a / x + 1);
	}
	return 0;
}