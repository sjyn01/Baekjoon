#include <stdio.h>
int a[11], b[4];
int n, MIN = 1987654321, MAX = -1987654321;
void DFS(int m, int res)
{
	if (m == n)
	{
		if (MIN > res) MIN = res;
		if (MAX < res) MAX = res;
		return;
	}
	for (int i = 0; i<4; i++)
		if (b[i])
		{
			b[i]--;
			if (i == 0) DFS(m + 1, res + a[m]);
			else if (i == 1) DFS(m + 1, res - a[m]);
			else if (i == 2) DFS(m + 1, res * a[m]);
			else DFS(m + 1, res / a[m]);
			b[i]++;
		}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &b[i]);

	DFS(1, a[0]);

	printf("%d\n%d", MAX, MIN);
}