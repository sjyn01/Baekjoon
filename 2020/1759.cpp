#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
/*
�ٷ� ���� �ֹ��� ������ �� ���踦 �ָӴϿ� ���� ä �����ϰ� ����� �� ������ Ȳ���� ��Ȳ�� ������ ��������, 
702ȣ�� ���ο� ���� �ý����� ��ġ�ϱ�� �Ͽ���. �� ���� �ý����� ���谡 �ƴ� ��ȣ�� �����ϰ� �Ǿ� �ִ� �ý����̴�.

��ȣ�� ���� �ٸ� L���� ���ĺ� �ҹ��ڵ�� �����Ǹ� �ּ� �� ���� ������ �ּ� �� ���� �������� �����Ǿ� �ִٰ� �˷��� �ִ�. 
���� ���ĵ� ���ڿ��� ��ȣ�ϴ� �������� �������� �̷�� ���� ��ȣ�� �̷�� ���ĺ��� ��ȣ���� �����ϴ� ������ �迭�Ǿ��� ���̶�� �����ȴ�. 
��, abc�� ���ɼ��� �ִ� ��ȣ������ bac�� �׷��� �ʴ�.

�� ���� �ý��ۿ��� �������� ��ȣ�� ������� ���� ������ ������ C������ �ִٰ� �Ѵ�. 
�� ���ĺ��� �Լ��� �ν�, ���� ������ �������� �濡 ħ���ϱ� ���� ��ȣ�� ������ ������ �Ѵ�. 
C���� ���ڵ��� ��� �־����� ��, ���ɼ� �ִ� ��ȣ���� ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
int checkVow(bool arr[]) {
	int value = 0;
	for (int i = 0; i < 26; i++) {
		if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
			if (arr[i] == true) value++;
		}
	}
	return value;
}
int checkCons(bool arr[]) {
	int value = 0;
	for (int i = 0; i < 26; i++) {
		if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
		}
		else value++;
	}
	return value;
}
int main() {
	char alpa[15];
	int beta[15];
	int num1, num2;

	//�ּ� �Ѱ��� ������ �ΰ��� ����
	//a e i o u
	//ASCII������ �̿�? 97, 101, 105, 111, 117 ---> 0 4 8 14 20  26�����̴ϱ� 0 - 25 index
	cin >> num1 >> num2;
	for (int i = 0; i < num2; i++) {
		cin >> alpa[i];
	}
	sort(alpa, alpa + num2); // ������������ ����

	for (int i = 0; i < num2; i++) { // ���õ� ���ڴ� 0 �ƴ� ���ڴ� 1�μ� ����
		if (i < num1) beta[i] = 0;
		else beta[i] = 1;
	}
	do {
		bool cons[26] = { false };

		int bvalue = 0;
		int avalue = 0;
		for (int i = 0; i < num2; i++) {
			if (!beta[i]) {
				cons[alpa[i] - 97] = true;
			}
		}
		avalue = checkCons(cons); //����
		bvalue = checkVow(cons); //����
		
		if (avalue >= 2 && bvalue >= 1) {
			for (int i = 0; i < num2; i++) {
				if (!beta[i]) {
					cout << alpa[i];
				}
			}
			cout << '\n';
		}		
	} while (next_permutation(beta, beta + num2));

	return 0;
}