#include <stdio.h>

int V;
int E;

int edge[10][3]; // E가 최대 10개인 경우.. 

void sort(int left, int right);

int main(void) 
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++)
	{
		scanf("%d %d %d", &edge[i][0], &edge[i][1], &edge[i][2]);
	} 
	sort(0, E-1);

	return 0;
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
