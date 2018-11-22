#include <stdio.h>

int d[11][11];
int p[11]; 

int find(int n);
int main(void) 
{
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		int N;
		int n1, n2;
		int result = 1;
		scanf("%d", &N);
		scanf("%d %d", &n1, &n2);
		p[0] = n1;
		p[1] = n2;
		for(int i = 2; i<=N; i++)
		{
			scanf("%d %d", &n1, &n2);
			if(p[i-1] != n1)
			{
				result = 0;
			}
			p[i] = n2;
		}
		if(result!=0)
		{
			result = find(N);
		}
		printf("#%d %d\n", tc, result);
	}
	return 0;
}

int find(int n)
{
	
	for(int l = 1; l < n; l++)
	{
		for(int i = 1; i <= n - l; i++)
		{
			int j = i + l;
			int minV = 0x7fffffff;
			for(int k = i; k < j; k++)
			{
				if( minV > (d[i][k] + d[k+1][j] + p[i-1]*p[k]*p[j]))
				{
					minV = d[i][k] + d[k+1][j] + p[i-1]*p[k]*p[j];
				}
			}
			d[i][j] = minV;
		}	
	}
	return d[1][n];	
}
