#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[100001];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 2e9;
	int left_ans = 0, right_ans = 0;
	int start = 0, end = n - 1;
	int temp = 0;

	while(start<end) {	
		long long temp = abs(arr[start] + arr[end]);

		if (ans > temp) {
			ans = temp;
			left_ans = arr[start];
			right_ans = arr[end];
		}
		
		if (arr[start] + arr[end] > 0) end--;
		else start++;
	}

	cout << left_ans << " " << right_ans << '\n';
	return 0;
}