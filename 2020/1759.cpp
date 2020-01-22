#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
/*
바로 어제 최백준 조교가 방 열쇠를 주머니에 넣은 채 깜빡하고 서울로 가 버리는 황당한 상황에 직면한 조교들은, 
702호에 새로운 보안 시스템을 설치하기로 하였다. 이 보안 시스템은 열쇠가 아닌 암호로 동작하게 되어 있는 시스템이다.

암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음과 최소 두 개의 자음으로 구성되어 있다고 알려져 있다. 
또한 정렬된 문자열을 선호하는 조교들의 성향으로 미루어 보아 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었을 것이라고 추측된다. 
즉, abc는 가능성이 있는 암호이지만 bac는 그렇지 않다.

새 보안 시스템에서 조교들이 암호로 사용했을 법한 문자의 종류는 C가지가 있다고 한다. 
이 알파벳을 입수한 민식, 영식 형제는 조교들의 방에 침투하기 위해 암호를 추측해 보려고 한다. 
C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호들을 모두 구하는 프로그램을 작성하시오.
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

	//최소 한개의 모음과 두개의 자음
	//a e i o u
	//ASCII값으로 이용? 97, 101, 105, 111, 117 ---> 0 4 8 14 20  26가지이니까 0 - 25 index
	cin >> num1 >> num2;
	for (int i = 0; i < num2; i++) {
		cin >> alpa[i];
	}
	sort(alpa, alpa + num2); // 오름차순으로 정렬

	for (int i = 0; i < num2; i++) { // 선택된 문자는 0 아닌 문자는 1로서 순열
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
		avalue = checkCons(cons); //자음
		bvalue = checkVow(cons); //모음
		
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