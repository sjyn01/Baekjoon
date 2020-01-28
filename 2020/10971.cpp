#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define SIZE 10
using namespace std;

int way[SIZE][SIZE];

//�־��� �뼱�� �� �� �ִ� ������� �ľ�
bool RouteIsRight(vector<int>& v) {
	for (int i = 1; i < v.size(); ++i) {
		if (way[v[i - 1]][v[i]] <= 0)
			return false;
	}

	if (way[v[v.size() - 1]][v[0]] <= 0)
		return false;
	return true;
}

//�־��� ���ø� ��ȸ���� ��, �� ����� ����ؼ� ����
int CalcCost(vector<int>& v) {

	int cost = 0; //��ȸ���� �� ��� ����� ������ ����

	for (int i = 1; i < v.size(); ++i) {
		//way[i][j] => i -> j�� ���� ����� �ǹ�
		cost += way[v[i - 1]][v[i]];
	}
	//������ ���ÿ��� �ٽ� ����� ���÷� ���ƿ��� ��뵵 ��������Ѵ�.
	cost += way[v[v.size() - 1]][v[0]];
	return cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	//������ ��ȣ 0���� �ϱ�� ���ϸ�, (�ε��� 0���� ����)
	vector<int> city(n);
	for (int i = 0; i < n; ++i) {
		city[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> way[i][j];
		}
	}

	int ans = INT_MAX; //���� �� ���� ���� ū ���� ����ִ´�.

	do {
		if (RouteIsRight(city)) { //�� �� �ִ� ������ �Ǵ� ��
			ans = min(ans, CalcCost(city)); //���� ����� �����Ѵ�.
		}
	} while (next_permutation(city.begin()+1, city.end()));

	cout << ans;
	return 0;
}