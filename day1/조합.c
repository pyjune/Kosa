#include <stdio.h>

int a[] = {1, 2, 3, 4, 5};
int c[3];

void nck(int n, int k, int m);

int main(void) 
{
	nck(5, 3, 3);
	return 0;
}

void nck(int n, int k, int m)
{
	if( k == 0)
	{
		for(int i = 0; i < m; i++)
		{
			printf("%d ", c[i]);
		}
		printf("\n");
	}
	else if( n < k)
	{
		return;
	}
	else
	{
		c[k-1] = a[n-1]; // a[n-1]을 포함하는 경우
		nck(n-1, k-1, m);
		nck(n-1, k, m); 	// a[n-1]을 포함하지 않는 경우 
	}
}
