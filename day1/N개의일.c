#include <stdio.h>

int used[10];
int p[10];
int t[10][10];
int minV;
int cnt;
void npr(int n, int k, int m);

int main(void) 
{
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		int N;
		minV = 100;
		cnt = 0;
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%d", &t[i][j]);
			}		
		}
		//npr( 0, N, N);
		npr2( 0, N, N, 0);
		printf("#%d %d %d\n", tc, minV, cnt);
	}
	return 0;
}
void npr2(int n, int k, int m, int s) // n-1번 사람까지 일을 하는데 걸리는 시간 s 
{
	cnt++;
	if(n == k)
	{
		if( minV > s)
		{
			minV = s;
		} 
	}
	else if( s >= minV ) // 아직 배정할 일이 남았지만 최소시간을 초과하는 경우 
	{
		return;
	}
	else
	{
		for(int i = 0; i < m; i++)
		{
			if( used[i] == 0) // a[i]를 사용하지 않았으면 
			{
				used[i] = 1; // 사용했음으로 표시.. 
				p[n] = i;
				npr2( n + 1, k, m, s + t[p[n]][n] ); // s + t[p[n]][n] n번일까지 하는데 걸리는 시간 
				used[i] = 0; // 다른 자리에서 사용할 수 있도록 함. 
			}
		}
	}
}
void npr(int n, int k, int m)
{
	cnt++;
	if(n == k)
	{
		int s = 0;
		for( int i = 0; i < k; i++)
		{
			s += t[p[i]][i]; // i번 일을 맡은 사람 p[i]가 i번일을 하는데 걸리는 시간 
		}
		if(minV > s)
		{
			minV = s;
		} 
	}
	else
	{
		for(int i = 0; i < m; i++)
		{
			if( used[i] == 0) // a[i]를 사용하지 않았으면 
			{
				used[i] = 1; // 사용했음으로 표시.. 
				p[n] = i;
				npr( n + 1, k, m );
				used[i] = 0; // 다른 자리에서 사용할 수 있도록 함. 
			}
		}
	}
}
