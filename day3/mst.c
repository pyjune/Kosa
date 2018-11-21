#include <stdio.h>

int V;
int E;

int edge[10][3]; // E가 최대 10개인 경우.. 
int p[6]; // 마지막 노드 V가 5인경우.. 대표원소 저장. 

void sort(int left, int right);
int rep(int n);

int main(void) 
{
	int cnt;
	int j;
	int s;
	 
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for(int i = 1; i<=V; i++)
	{
		p[i] = i; // 자기자신을 대표원소로 초기화 
	} 
	for(int i = 0; i < E; i++)
	{
		scanf("%d %d %d", &edge[i][0], &edge[i][1], &edge[i][2]);
	} 
	sort(0, E-1); // 가중치 순으로 오름차순 정렬
	
	cnt = 1;
	j = 0;
	s = 0;
	while( cnt < V ) // V-1개의 edge를 선택.. 
	{
		if(rep(edge[j][0]) != rep(edge[j][1])) // j번 edge에 속한  두 노드의 대표원소가 다르면.. 
		{
			cnt++; // 사이클을 형성하지 않으므로 edge 추가 
			p[rep(edge[j][1])] = rep(edge[j][0]); // mst에 포함되므로 대표값을 일치시킴 
			s += edge[j][2];	// mst에 추가된 edge의 가중치 누적 
		}
		j++;
	}
	printf("%d\n", s);
	
	return 0;
}

int rep(int n) // n의 대표원소를 반환하는 함수 
{
	while( p[n] != n)
	{
		n = p[n];
	}
	return n;
}

void sort(int left, int right)
{
	int i = left - 1;
	int t;
	if(left < right)
	{ 
		for(int j = left ; j < right; j++)
		{
			if( edge[j][2] < edge[right][2] ) // a[j]가 pivot보다 작으면
			{
				i++;
				if( i != j ) // pivot보다 큰 값이 i, j사이에 있으면	
				{
					t = edge[j][0];
					edge[j][0] = edge[i][0];
					edge[i][0] = t;
					
					t = edge[j][1];
					edge[j][1] = edge[i][1];
					edge[i][1] = t;
					
					t = edge[j][2];
					edge[j][2] = edge[i][2];
					edge[i][2] = t;
				}
			} 
		}
		t = edge[i+1][0];
		edge[i+1][0] = edge[right][0];
		edge[right][0] = t;  // pivot은 정렬 완료...
		
		t = edge[i+1][1];
		edge[i+1][1] = edge[right][1];
		edge[right][1] = t;
		
		t = edge[i+1][2];
		edge[i+1][2] = edge[right][2];
		edge[right][2] = t;
		
		sort(left, i); // pivot의 왼쪽 구간 
		sort(i+2, right);  // pivot의 오른쪽 구간..
	}
}
