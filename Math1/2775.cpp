#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	//0층 1호 - 1명 2호 - 2명 3호 - 3명 ...
	//1층 1호 - 1명 2호 - 1+2명 3호 - 1+2+3명 4호 - 1+2+3+4
	//2층 1호 - 1명 2호 - 1+(1+2)명 3호 1+명 4호 1+3+6+10
	
	//k와 n (k-1) 1 + 2 + 3 + 4 .... + n
	
	int arr[15][15];
	arr[0][0] = 1;
	for (int i = 1; i<15; i++) {
		arr[0][i] = i + 1;
		arr[i][0] = 1;
	}
	for (int i = 1; i<15; i++) {
		for (int j = 1; j<15; j++) {
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
	}
	int num,a,b;
	scanf("%d\n", &num);
	while (num--) {
		scanf("%d", &a);
		scanf("%d", &b);
		printf("%d\n", arr[a][b-1]);
	}

	return 0;

}
//출처 http://blog.naver.com/PostView.nhn?blogId=zsujinz&logNo=220930013087&parentCategoryNo=&categoryNo=1&viewDate=&isShowPopularPosts=false&from=section
// dp의 basic한 예제이다.....