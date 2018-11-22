#include <stdio.h>

int m[501][501];
int d[501][501]; 

int main() 
{
	int T;
	freopen("input.txt","r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc<=T; tc++)
	{
		int N;
		int k = 0;
		int s = 0;
		scanf("%d", &N);
		for(int i=1; i<=N; i++)
		{
		    for(int j=1; j<=N; j++)
		    {
		        m[i][j]= (k++)%10+1;
		    }
		}
		for(int i = 1; i<=N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + m[i][j];
			}
		}
		for(int i = 0; i<N; i++)
		{
			int r1, c1, r2, c2;
			scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
			s += d[r2][c2] - d[r1-1][c2] - d[r2][c1-1] + d[r1-1][c1-1];
		}
		printf("#%d %d\n", tc, s);
	}
	
	return 0;
}
