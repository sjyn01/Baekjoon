#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
int main() {
	int x, y, num,count;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &x, &y);
		count = 1;
		double minN, maxN;
		while (1) {
			minN = pow(count, 2) - count + 1;
			maxN = pow(count, 2) + count;
			if (minN <= y-x && y-x<=maxN) {
				if (minN <= y - x && y - x <= pow(count,2)) printf("%d\n", 2 * count - 1);
				else printf("%d\n",2 * count);
				break;
			}
			else count++;
		}	
	}

	return 0;
}