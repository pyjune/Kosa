#include <stdio.h>

int m[100][100];
int N;
// dfs 
int find(int r, int c);
int find2(int r, int c);

// bfs
int q[10000];
int front, rear;
int find3(int r, int c);
int visited[100][100];

int main(void) 
{
	int T;
	int sr, sc;
	int d;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%1d", &d);
				m[i][j] = d;
				if(d == 2) // 시작 좌표 
				{
					sr = i;
					sc = j;
				}
			}
		}
		printf("#%d %d\n", tc, find3(sr, sc));
	}

	return 0;
}

int find(int r, int c)
{
	if( m[r][c] == 3 ) //  목적지 도착.. 
	{
		return 1; 
	}
	else if( m[r][c] == 1) // 일단 이동 후 벽인지 확인.. 
	{
		return 0;
	}
	else
	{
		m[r][c] = 1;
		if(find( r, c + 1))
			return 1;
		if(find( r + 1, c))
			return 1;
		if(find( r, c - 1))
			return 1;
		if(find( r - 1, c))
			return 1;
		return 0;
	}
}

int find2(int r, int c)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	
	if( m[r][c] == 3 ) //  목적지 도착.. 
	{
		return 1; 
	}
	else
	{
		int nr, nc;
		m[r][c] = 1;
		for(int i = 0; i < 4; i++)
		{
			nr = r + dr[i];
			nc = c + dc[i];
			if( m[nr][nc] != 1 ) // 새 좌표가 벽이 아니면 이동 (r, c에 인접인 칸) 
			{
				if(find2(nr, nc))
				{
					return 1;
				}
			}
		}
		return 0;
	}
}
// bfs
int find3(int r, int c)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	int nr, nc;
	
	front = -1;
	rear = -1;
	q[++rear] = r;
	q[++rear] = c;
	visited[r][c] = 1; // 출발점 
	while( front != rear )
	{
		r = q[++front];
		c = q[++front];
		if( m[r][c] == 3)
		{
			return 1; // 목적지에 도착한 경우.. 
		}
		// 인접이고 미방문인 칸 인큐..
		for(int i = 0; i < 4; i++)
		{
			nr = r + dr[i];
			nc = c + dc[i];
			if(( m[nr][nc] != 1 )&&(visited[nr][nc] == 0)) // 벽이아니고 미방문이면.. 
			{
				q[++rear] = nr;
				q[++rear] = nc;
				visited[nr][nc] = 1;
			}
		} 
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			visited[i][j] = 0;
		}
	}
	return 0; // 목적지에 도착할 수 없는 경우 
}
