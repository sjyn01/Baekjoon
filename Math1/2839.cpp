#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Nų�α׷�(n) ��� 3KG ����(a) 5KG ����(b) --> �ִ��� ���� ���� ��
int main() { //���� ������ ���
	int n;
	scanf("%d", &n);
	int b = n / 5; 
	if (n >= 3 && n <= 5000) {
		if (n % 5 == 0) printf("%d", b); //�켱 5�� ����̸� ���� �ּ����� ������
		else { // ������ ��� 5�� ���� ���� 1�� ���鼭 ���� 0 �̸����� �������� ������ ���ϸ� -1
			   // ���⼭ ���� 0�ε� ���� ���ϴ� ���� 3kg ¥�� ������ ����ϴ� ����
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
/*Greedy�� Ǯ �� �ִ� �����ε� ��̴�. �˰��� å�� �ٽ� �ѹ� ���� �� �� ����
Ǯ�� : http://blog.naver.com/PostView.nhn?blogId=occidere&logNo=220938670879&categoryNo=0&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView*/
