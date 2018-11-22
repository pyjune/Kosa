#include <stdio.h>

int a[] ={0, 1,1,2,2,1};

int d[6][11];

int main(void) 
{
	for(int i = 0; i<=5; i++)
	{
		d[i][0] = 1; // j가 0인 경우는 모두 True 
	}
	for(int i = 1; i<=5; i++)
	{
		for(int j = 1; j<=10; j++)
		{
			if(j - a[i]>=0)
				d[i][j] = d[i-1][j] || d[i-1][j-a[i]];
			else
				d[i][j] = d[i-1][j];
		}
	}
	printf("%d\n", d[5][5]);
	return 0;
}
