#include <stdio.h>

/*
5 6
1 2 1 3 3 2 2 5 5 4 3 4
*/

int adj[11][11]; // 마지막 노드 V<=10 인경우..
int visited[11];

int V;
int E; 

int find(n, k);// n에서 k까지의 최단거리 찾기 


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
	printf("%d\n", find(1, 4));
	
	return 0;
}
int find(int n, int k) // BFS
{
	int q[10];
	int front = -1;
	int rear = -1; 
	q[++rear] = n;
	visited[n] = 1;
	while( front != rear )
	{
		n = q[++front];
		if( n == k ) // 노드에 대한 처리.. 
		{
			return (visited[n] - 1); // k까지 거쳐간 최소 간선 수 리턴 
		}
		for(int i = 1; i <=V; i++)
		{
			if(( adj[n][i] != 0 ) && ( visited[i] == 0 )) // 인접하고 미방문이면..
			{
				q[++rear] = i; // enqueue
				visited[i] = visited[n] + 1;
			} 
		}
	}
	return 0; // 경로가 존재하지 않는 경우.. 
}
