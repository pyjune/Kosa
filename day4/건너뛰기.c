#include <stdio.h>

int d[21][21];
int a[21][21];
int N, M;

int main(void) 
{
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc<=T; tc++)
	{
		scanf("%d %d", &N, &M);
		for(int i =1; i<=N; i++)
		{
			for(int j = 1; j<=M; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}

		d[1][1] = 1;
		for(int i = 1; i<=N; i++)
		{
			for(int j = 1; j<=M; j++)
			{
				for(int k = 1; k<=3; k++)
				{
					if(((i-k)>=1) && (a[i-k][j] == k))
					{
						d[i][j] += d[i-k][j];
					}
					if(((j-k)>=1) &&(a[i][j-k] == k))
					{
						d[i][j] += d[i][j-k];
					}
				}
			}
			
		}
		printf("#%d %d\n", tc, d[N][M]);
		for(int i= 1; i<=N; i++)
		{
			for(int j = 1; j<=M; j++)
			{
				d[i][j] = 0;
			}
		}
	}
	return 0;
}
