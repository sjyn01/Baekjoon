#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//1 2 4 7

int main() {
	int x, sum=0, count = 1;;
	scanf("%d", &x);
	if (x == 1) printf("%d/%d", x/x);
	else {
		while (sum <= x) {
			count++;
			sum = 1 + count * (count - 1) / 2;
		}
		int a = count - (sum - x);
		if(count%2==1) printf("%d/%d", a, count-a); // 몇번째냐 너가 count-(sum-x) / sum-x
		else printf("%d/%d", count - a, a);
	}
}