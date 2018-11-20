#include <stdio.h>

int m[100][100];
int N;
// dfs 
void find(int r, int c, int e);
int minV;
// bfs
int q[10000];
int front, rear;
int bfs(int r, int c);
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
		minV = 10000;
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
//		find(sr, sc, 0);
//		if(minV == 10000)
//		{
//			minV = 1; // 도착할 수 없는 경우 (출력할 때 -1을 고려) 
//		}
		//printf("#%d %d\n", tc, minV - 1);
		printf("#%d %d\n", tc, bfs(sr, sc));
	}

	return 0;
}

void find(int r, int c, int e)
{
	if( m[r][c] == 3 ) //  목적지 도착.. 
	{
		if(minV > e)
		{
			minV = e;	
		} 
	}
	else if( m[r][c] == 1) // 일단 이동 후 벽인지 확인.. 
	{
		return;
	}
	else
	{
		m[r][c] = 1;
		find( r, c + 1, e + 1);
		find( r + 1, c, e + 1);
		find( r, c - 1, e + 1);
		find( r - 1, c, e + 1);
		m[r][c] = 0;
	}
}

int bfs(int r, int c)
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
			return (visited[r][c] - 2); // 목적지에 도착한 경우.. 
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
				visited[nr][nc] = visited[r][c] + 1;
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
