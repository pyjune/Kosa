#include <stdio.h>

int arr[101][101];
int d[101][101];
int N, M;
void find(void);
void f(int i, int j, int s);
int maxV;

int main(void) 
{
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		maxV = 0;
		scanf("%d %d", &N, &M);
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= M; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		find();
		printf("#%d %d\n", tc, d[N][M]);
		//f(1, 1, 0); // 재귀는 10x10 이내인 경우만 가능.. 
		//printf("#%d %d\n", tc, maxV);
	}

	return 0;
}

void f(int i, int j, int s)
{
	if((i == N)&&(j == M))
	{
		if(maxV < s+arr[N][M])
		{
			maxV = s+arr[N][M];
		}
	}
	else
	{
		if( j+1<=M)
			f(i, j+1, s+arr[i][j]);
		if( i+1<=N)
			f(i+1, j, s+arr[i][j]);
	}
}

void find(void)
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j<=M; j++)
		{
			d[i][j] = ((d[i-1][j] > d[i][j-1])?d[i-1][j]:d[i][j-1]) + arr[i][j];
		}
	}
}
