#include <iostream> 

using namespace std;

int cnt_0[41] = { 1,0, };
int cnt_1[41] = { 0,1, };

int main() { 

	int T,n;

	cin >> T;

	for (int i=0; i<T; i++) { 
		cin >> n;
		for (int j = 2 ; j<=n; j++) { 
			cnt_0[j] = cnt_0[j-1] + cnt_0[j-2];
			cnt_1[j] = cnt_1[j-1] + cnt_1[j-2];
		} 
		cout << cnt_0[n] << ' ' << cnt_1[n] << '\n';
	} 

	return 0;
}
