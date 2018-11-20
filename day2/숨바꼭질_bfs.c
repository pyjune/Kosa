#include <stdio.h>

int q[100000];
int front = -1;
int rear = -1;

int visited[100001];
int bfs2(int n, int k);
int main(void) 
{
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d\n", bfs2(N, K));
	
	return 0;
}

int bfs2(int n, int k)
{
	// 초기화
	q[++rear] = n; // 시작노드 인큐
	visited[n] = 1; // 방문표시 
	// 반복 
	while( front != rear ) // 큐가 비어있지 않으면 반복 
	{
		n = q[++front]; // 디큐
		if( n == k ) // 
		{
			return (visited[n] - 1);
		}
		// 인접이고 미방문이면...
		if((( n - 1 ) >= 0) && (visited[n - 1] == 0))
		{
			q[++rear] = n - 1;
			visited[n - 1] = visited[n] + 1;
		}
		if((( n + 1 ) <= 100000) && (visited[n + 1] == 0))
		{
			q[++rear] = n + 1;
			visited[n + 1] = visited[n] + 1;
		}
		if((( n * 2 ) <= 100000) && (visited[n * 2] == 0))
		{
			q[++rear] = n * 2;
			visited[n * 2] = visited[n] + 1;
		}
	}
	return 0; // k에 도착할 수 없는 경우 
}
