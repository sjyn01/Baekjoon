#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//1 --->1번
//2 3 4 5 6 7  --->2번
//8 9 10 11 12 13 14 15 16 17 18 19  --->3번
//bn = 6n --> an = 3(n-1)(n-2)+2
int main(void)
{
	int n, cnt = 1, sum = 0;

	scanf("%d", &n);

	if (n == 1)	printf("%d", cnt);
	else {
		while (sum <= n) {
			cnt++;
			sum = 2 + 3 * cnt*(cnt - 1);
		}
		printf("%d\n", cnt);
	}

}

// 계차수열 https://terms.naver.com/entry.nhn?docId=3350261&cid=60210&categoryId=60210
// 출처: https://young21story.tistory.com/22 