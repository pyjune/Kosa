#include <stdio.h>

/*
물건의 개수, 상자의 부피,
각 물건의 부피, 가치 
4 10
6 12
5 10
5 15
4 6
*/
int d[5][11];
int w[5]; // 물건의 부피 
int v[5]; // 물건의 가치 

int main(void) 
{
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i= 1; i<=N;i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		w[i] = n1;
		v[i] = n2;
	} 
	for( int i = 1; i <= N; i++) // i번 물건 
	{
		for(int j = 1; j<= M; j++) // 상자의 크기 j 
		{
			if( j < w[i])
			{
				d[i][j] = d[i-1][j];
			}
			else
			{
				d[i][j] = d[i-1][j] > (d[i-1][j-w[i]] + v[i])?d[i-1][j]:(d[i-1][j-w[i]] + v[i]);
			}
		}
	}
	printf("%d\n", d[N][M]);
	return 0;
}
