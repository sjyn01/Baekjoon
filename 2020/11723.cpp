#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char mes[10];
	int s[20];
	int num;
	int x;

	for (int i = 0; i < 20; i++) {
		s[i] = 0;
	}

	scanf("%d", &num);
	
	for (int i = 0; i < num; i++) {
		scanf("%s", mes);
		if (!strcmp(mes, "all")) {
			for (int j = 0; j < 20; j++) {
				s[j] = j+1;
			}
		}
		else if (!strcmp(mes, "empty")) {
			for (int j = 0; j < 20; j++) {
				s[j] = 0;
			}
		}
		else {
			scanf("%d", &x);

			if (!strcmp(mes, "add") && !s[x - 1]) {
				s[x - 1] = x;
			}
			else if (!strcmp(mes, "remove") && s[x - 1]) {
				s[x - 1] = 0;
			}
			else if (!strcmp(mes, "check")) {
				if (s[x - 1] == x) printf("1\n");
				else printf("0\n");
			}
			else if (!strcmp(mes, "toggle")) {
				if (s[x - 1] == x) s[x - 1] = 0;
				else s[x - 1] = x;
			}
		}
	}
}
