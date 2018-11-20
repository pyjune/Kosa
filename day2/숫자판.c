#include <stdio.h>

int p[10];
int m[10][10];
int used[10][10];
int N, M;

int find(void);

int main() 
{
	int T;
	freopen("input.txt","r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for(int i = 0 ; i < N; i++)
		{
			scanf("%d", &p[i]);
		}
		scanf("%d", &M);
		for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < M; j++)
			{
				scanf("%d", &m[i][j]);
			}
		}
		printf("#%d %d\n", tc, find());
		for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < M; j++)
			{
				used[i][j] = 0;
			}
		}
	}
	return 0;
}

int find(void)
{
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(m[i][j] == p[0])
			{
				if(dfs(i, j, 0) == 1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int dfs(int r, int c, int k) // r, c 위치의 k인덱스까지 탐색.. 
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	int nr, nc;
	
	if( k == N ) // 모든 숫자를 찾은 경우..
	{
		return 1;
	}
	else if( m[r][c] != p[k])
	{
		return 0;
	}
	else // m[r][c] == p[k] 인 경우.. 
	{
		used[r][c] = 1;
		for(int i = 0; i < 4; i++)
		{
			nr = r + dr[i];
			nc = c + dc[i];
			if(0<=nr && nr<M  && 0<=nc && nc<M)
			{
				if(used[nr][nc] ==0)
				{
					if(dfs(nr, nc, k + 1))
					{
						return 1;
					}
				}
			} 	
		}
		used[r][c] = 0;
		return 0;
	}
}
