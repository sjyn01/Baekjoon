#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int size=0;
	int input[12];
	int num;
	int check[12];
	//1�� 0���� �̷���� ���� ����� size�� ����... ���߿� 6���ϱ� 0�� 6�� 1�� size-6��

	while (1) {
		cin >> size;
		if (size == 0) break;
		for (int i = 0; i < size; i++) {
			cin >> num;
			input[i] = num;
			if (i < 6) check[i] = 0;
			else check[i] = 1;
		}
		do {
			for (int i = 0; i < size; i++) {
				if (!check[i]) cout << input[i] << ' ';
			}
			cout << '\n';
		} while (next_permutation(check, check + size));
		cout << '\n';
	}

}