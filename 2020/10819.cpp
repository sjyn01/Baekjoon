#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 8
int calculate(int arr[], int num) {
	int sum = 0;
	for (int i = 1; i < num; i++) {
		sum += abs(arr[i] - arr[i - 1]);
	}
	return sum;
}

int main() {
	int total = 0;
	int num;
	int a[8];
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a[i];
	}
	sort(a, a+num);
	do {
		int temp = calculate(a, num);
		total = max(total, temp);
	} while (next_permutation(a, a + num));
	cout << total << '\n';
	return 0;
}