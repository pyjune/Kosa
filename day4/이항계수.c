#include <stdio.h>

long long d[71][71];


int main(void) 
{
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);
		find(n, a);
		printf("#%d %lld\n", tc, d[n][a]);
	}
	return 0;
}

void find(int n, int k)
{
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if((i != j) && (j != 0))
			{
				d[i][j] = d[i-1][j-1] + d[i-1][j];
			}
			else
			{
				d[i][j] = 1;
			}
		}
	}
}
