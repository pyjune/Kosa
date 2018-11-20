#include <stdio.h>
/*
5 6
1 2 1 3 3 2 2 5 5 4 3 4
*/

int adj[11][11]; // 마지막 노드 V<=10 인경우..
int visited[11];

int V;
int E; 
void dfs(int n);
//dfs2
int stack[10];
int top = -1;
void dfs2(int n);
// dfs3
int cnt;
void dfs3(int n, int k);
// dfs4
int minV;
void dfs4(int n, int k, int e);

int main(void) 
{
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		//adj[n2][n1] = 1; // 방향이 없는 경우 
	}
	//dfs(1);
	//dfs2(1);
	//dfs3(1, 4);
	//printf("%d\n", cnt);
	minV = E;
	dfs4(1, 4, 0);
	printf("%d\n", minV);
	return 0;
}
//
void dfs4(int n, int k, int e) // 최단 거리 찾기 
{
	if( n == k)
	{
		if(minV > e)
		{
			minV = e;
		} 
	}
	else
	{
		visited[n] = 1;
		for(int i = 1; i <= V; i++) // 모든 노드 i에 대해 
		{
			if((adj[n][i] != 0) && (visited[i] == 0)) // 인접이고 미방문이면..
			{
				dfs4(i, k, e + 1); // i로 이동	
			} 
		}
		visited[n] = 0; // 다른 경로를 통해 n으로 진입할 수 있도록... 
	}
}
// 경로의 수
void dfs3(int n, int k)
{
	if( n == k)
	{
		cnt++;
	}
	else
	{
		visited[n] = 1;
		for(int i = 1; i <= V; i++) // 모든 노드 i에 대해 
		{
			if((adj[n][i] != 0) && (visited[i] == 0)) // 인접이고 미방문이면..
			{
				dfs3(i, k); // i로 이동	
			} 
		}
		visited[n] = 0; // 다른 경로를 통해 n으로 진입할 수 있도록... 
	}
}
// 반복
void dfs2(int n)
{
	stack[++top] = n; // 시작노드 push() 
	visited[n] = 1;	// 방문 표시 
	while( top != -1 ) // 큐가 비어있지 않으면
	{
		n = stack[top--]; // pop()
		printf("%d ", n);
		for(int i = 1; i <=V; i++)
		{
			if((adj[n][i] != 0) && (visited[i] == 0))
			{
				stack[++top] = i;
				visited[i] = 1;
			}
		}	
	} 
}

void dfs(int n)
{
	visited[n] = 1;
	printf("%d ", n);
	for(int i = 1; i <= V; i++) // 모든 노드 i에 대해 
	{
		if((adj[n][i] != 0) && (visited[i] == 0)) // 인접이고 미방문이면..
		{
			dfs(i); // i로 이동	
		} 
	}
}
