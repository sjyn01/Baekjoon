#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;
	//총 생산수(i) * 가격(c) >= 고정비용(a) + 총 생산수(i) * 가변비용(b)
	scanf("%d %d %d", &a, &b, &c);
	int x = c - b;
	if (x <= 0) printf("-1\n");//가변비용이 더 크면 수익이 발생 x
	else {
		printf("%d", a / x + 1);
	}
	return 0;
}