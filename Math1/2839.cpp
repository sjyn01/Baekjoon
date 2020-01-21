#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//N킬로그램(n) 배달 3KG 봉지(a) 5KG 봉지(b) --> 최대한 적은 봉지 수
int main() { //봉투 가능한 경우
	int n;
	scanf("%d", &n);
	int b = n / 5; 
	if (n >= 3 && n <= 5000) {
		if (n % 5 == 0) printf("%d", b); //우선 5의 배수이면 가장 최소한의 봉투수
		else { // 나머지 경우 5로 나눈 몫을 1씩 빼면서 몫이 0 미만까지 봉투수를 구하지 못하면 -1
			   // 여기서 몫이 0인데 값을 구하는 경우는 3kg 짜리 봉투만 써야하는 숫자
			for (; b >= 0; b--) {
				if ((n - (b * 5)) % 3 == 0) {
					printf("%d", b + (n - (b * 5)) / 3);
					break;
				}
			}
			if (b<0) printf("-1\n");
		}
	}
	return 0;
}
/*Greedy로 풀 수 있는 문제인데 헤맸다. 알고리즘 책을 다시 한번 봐야 할 것 같다
풀이 : http://blog.naver.com/PostView.nhn?blogId=occidere&logNo=220938670879&categoryNo=0&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView*/
