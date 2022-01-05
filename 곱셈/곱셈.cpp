#include <iostream>
#include <algorithm>

using namespace std;
long long a, b, c;

long long divide_conquer(long long a, long long b) {

	if (b == 1) return a;

	else {
		long long temp = divide_conquer(a, b / 2);
		
		if (b % 2) 
			return ((temp * temp) % c * a) % c;
		else 
			return (temp * temp) % c;
	}
}

int main() {
	cin >> a >> b >> c;
	cout << divide_conquer(a, b) % c << '\n';

	return 0;
}