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

int stack[10];
int top = -1;
void dfs2(int n);

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
	dfs2(1);
	return 0;
}

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
