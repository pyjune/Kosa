#include <stdio.h>

//int a[] = { 3, 1, 2, 7, 6, 4, 5, 1};
//int a[] = { 8, 7, 6, 4, 5, 3, 2, 1};
int a[1000];
int d[1000];

int main(void) 
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i<N; i++)
	{
		scanf("%d", &a[i]);
	}
	d[0] = 1;
	int maxLIS = 0;
	for(int i = 1; i<N; i++)
	{
		int maxV = 0;
		for(int j = 0; j < i; j++)
		{
			if( a[j] < a[i] ) // a[i]보다 작은 값 중 LIS가 가장 큰 값 찾기 
			{
				if(maxV < d[j] )
				{
					maxV = d[j];
				}
			}
		}
		d[i] = maxV + 1;
		if(maxLIS < d[i])
		{
			maxLIS = d[i];
		}
	}
	printf("%d\n", maxLIS);
	return 0;
}
