#include <stdio.h>

int dis[1001];
int adj[1001][1001];
int ind[1001];

int V, E;
int q[1000];
int front;
int rear;

void find(void);

int main(void) 
{
	int T;
	
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		front = -1;
		rear = -1;
		scanf("%d %d", &V, &E);
		for(int i = 0; i < E; i++)
		{
			int n1, n2, w;
			scanf("%d %d %d", &n1, &n2, &w);
			adj[n1][n2] = w;
			ind[n2]++;
		}
		find();
		printf("#%d %d\n", tc, dis[V]);
		for(int i = 0 ; i <= V; i++)
		{
			ind[i] = 0;
			dis[i] = 0;
			for(int j = 0; j <= V; j++)
			{
				adj[i][j] = 0;
			}
		}
	}
	
	return 0;
}

void find(void)
{
	int n;
	int maxV;
	q[++rear] = 0;
	dis[0] = 0;
	while(front != rear)
	{
		n = q[++front];
		// n노드에 대한 최장거리 결정 
		maxV = 0;
		for(int i = 0; i <= V; i++)
		{
			if(adj[i][n] != 0)
			{
				if( maxV < (dis[i] + adj[i][n]))
				{
					maxV = dis[i] + adj[i][n];
				}
			}
		}
		dis[n] = maxV;
		// 여기까지..
		for(int i = 0; i<= V; i++)
		{
			if( adj[n][i] != 0 )
			{
				ind[i]--; // n에 인접인 노드의 진입차수 감소
				if(ind[i] == 0) // i로 진입하는 모든 노드의 최장거리가 결정된 경우 
				{
					q[++rear] = i;
				} 
			}
		} 
	}
}
