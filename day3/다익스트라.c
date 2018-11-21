#include <stdio.h>

/*
5 6
1 3 1
1 2 3
3 2 1
2 5 4
5 4 2
3 4 2
*/
#define INF 0x7fffffff

int V;
int E;

int d[1001];
int u[1001];
int adj[1001][1001];

void dij(int s);
void bfs(int s);
int q[1000000];
int front = -1;
int rear = -1;

int main(void)
{
	int s, g;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for(int i = 1; i <=V; i++) // 인접행렬 초기화.. 
	{
		for(int j = 1; j <= V; j++)
		{
			if(i == j)
			{
				adj[i][j] = 0;
			}
			else
			{
				adj[i][j] = INF;
			}
		}
	}
	for(int i = 0; i < E; i++)
	{
		int n1, n2, w;
		scanf("%d %d %d", &n1, &n2, &w);
		if(adj[n1][n2] > w)
			adj[n1][n2] = w;
	}
	scanf("%d %d", &s, &g);
	dij(s);
	//bfs(1);
	printf("%d\n", d[g]); // s에서 V로 가는 최소 비용... 
	return 0;
}

void dij(int s) // 1번에서 다른 노드까지의 최소비용을 구하는 경우.. 
{
	int cnt; 
	int t;
	int minV;
	for(int i = 1; i <= V; i++)
	{
		d[i] = adj[s][i]; // 인접행렬에서 s 행의 값 복사 
	}
	u[s] = 1; // s는 경유지에서 제외..
	cnt = 1; // 경유지로 고려된 노드의 개수
	while( cnt < V )
	{
		minV = INF;
		for(int i = 1; i <= V; i++) // 경유지로 고려되지 않은 노드 i에 대해 d[i]가 최소인 노드 찾기 
		{
			if(( u[i] == 0 ) && (d[i] < minV)) 
			{
				t = i;
				minV = d[i];
			}
		}
		u[t] = 1; // t를 경유지로 고려
		for(int i = 1; i <= V; i++) // t에 인접인 노드 i에 대해.. 
		{
			if(( adj[t][i] !=0 ) && ( adj[t][i] != INF ))
			{
				if(d[t] != INF)
				{
					d[i] = (d[i]>(d[t] + adj[t][i])?(d[t] + adj[t][i]):d[i]);
				}	
			}
		} 
		cnt++; // 경유지 추가 
	} 
}

void bfs(int s)
{
	for(int i = 1; i <= V; i++)
	{
		d[i] = adj[s][i]; // 인접행렬에서 s 행의 값 복사 
	}
	for(int i = 1; i <= V; i++)
	{
		if((adj[s][i] != 0)&&(adj[s][i] != INF))
		{
			q[++rear] = i; // s에 인접인 노드 i 인큐 
		}
	}
	while( front != rear )
	{
		s = q[++front]; // 
		for(int i = 1; i <= V; i++)
		{
			if((adj[s][i] != 0)&&(adj[s][i] != INF))
			{
				if(d[s] != INF)
				{
					if( d[i] > (d[s] + adj[s][i]))
					{
						d[i] = d[s] + adj[s][i]; // i로 가는 비용이 갱신되면..
						q[++rear] = i; // i의 인접 노드도 비용이 갱신될 수 있으므로 인큐 
					}
				}
			}
		}
	}
}
