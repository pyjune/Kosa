#include <stdio.h>

int adj[101][101];
int coin[101];
int ind[101];

int q[100];
int front;
int rear;



int find(int n);

int main(void) 
{
	int T;
	int N;
	int K;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		front = -1;
		rear = -1;
		scanf("%d %d", &N, &K);
		for(int i = 0; i < K; i++)
		{
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			adj[n1][n2] = 1;
			ind[n2]++; // 진입차수는 도착으로 언급된 횟수 
		}
		printf("#%d %d\n", tc, find2(N));
		for(int i = 1; i<= N; i++)
		{
			ind[i] = 0;
			coin[i] = 0;
			for(int j = 1; j <= N; j++)
			{
				adj[i][j] = 0;
			}
		}
	}
	return 0;
}

int find2(int n)
{
	int t;
	int last;
	for(int i = 1; i <= n; i++) // 모든 사람 i에 대해 
	{
		if(ind[i] == 0) // 진입차수가 0이면 
		{
			q[++rear] = i; // enqueue
			coin[i] = 1;
		}
	}
	while( front != rear )
	{
		t = q[++front]; // dequeue
		int maxV = 0;
		for(int i = 1; i <= n; i++) // coin[t] 결정 
		{
			if( adj[i][t] !=0 )
			{
				if(maxV < coin[i])
				{
					maxV = coin[i];
				}
			}
		}
		coin[t] = maxV + 1;
		last = coin[t];
		for(int i = 1; i <= n; i++)
		{
			if( adj[t][i] != 0 ) // t->i 인접이면
			{
				ind[i]--; // i의 진입차수 감소 (i 앞의 노드 한개가 처리됨)
				if(ind[i] == 0) // i로 진입하는 모든 노드가 처리된 경우 
				{
					q[++rear] = i; // enqueue
				} 
			}
		}
	}
	return last;
}

int find(int n)
{
	int t;
	int last;
	for(int i = 1; i <= n; i++) // 모든 사람 i에 대해 
	{
		if(ind[i] == 0) // 진입차수가 0이면 
		{
			q[++rear] = i; // enqueue
			coin[i] = 1;
		}
	}
	while( front != rear )
	{
		t = q[++front]; // dequeue
		
		for(int i = 1; i <= n; i++)
		{
			if( adj[t][i] != 0 ) // t->i 인접이면
			{
				ind[i]--; // i의 진입차수 감소 (i 앞의 노드 한개가 처리됨)
				if(ind[i] == 0) // i로 진입하는 모든 노드가 처리된 경우 
				{
					q[++rear] = i; // enqueue
					coin[i] = coin[t] + 1;
					last = coin[i];
				} 
			}
		}
	}
	return last;
}
