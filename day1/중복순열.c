#include <stdio.h>

int a[] = {1,2,3};
int p[3];

void npir(int n, int k);

int main(void) {
	
	npir(0, 3);
	return 0;
}

void npir(int n, int k)
{
	if( n == k )
	{
		for(int i = 0; i < k; i++)
		{
			printf("%d ", p[i]);
		}
		printf("\n");
	}
	else
	{
		for(int i = 0; i < k; i++)
		{
			p[n] = a[i];
			npir(n + 1, k);
		}
	}
}
