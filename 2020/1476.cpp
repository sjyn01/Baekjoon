#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//int main() {
//
//	int a, b, c;
//	int e=1, f=1, g=1;
//	scanf("%d %d %d", &a, &b, &c);
//	for (int i = 1;; i++) {
//		if (e==a && f==b && g==c) {
//			printf("%d\n", i);
//			break;
//		}	
//		e += 1;
//		f += 1;
//		g += 1;
//		if (e == 16) e = 1;
//		if (f == 29) f = 1;
//		if (g == 20) g = 1;
//	}
//	return 0;
//}

//int main() {
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	a -= 1; b -= 1; c -= 1;
//	for (int i = 0;; i++) {
//		if (i % 15 == a && i % 28 == b && i % 19 == c) {
//			printf("%d\n", i+1);
//			break;
//		}
//	}
//}


//int main() {
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	for (int i = 1;; i++) {
//		if((i-a) % 15 == 0 && (i-b) % 28 == 0 && (i-c) % 19 ==0) {
//			printf("%d\n", i);
//			break;
//		}
//	}
//}