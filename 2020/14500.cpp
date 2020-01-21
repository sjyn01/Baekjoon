#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int row, col;
	int rtotal = 0;
	int ctotal = 0;
	scanf("%d %d",&row, &col);
	int arr[500][500];//¸Þ¸ð¸®³¶ºñ?
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col-4; j++) {
			
		}
	}

	return 0;
}