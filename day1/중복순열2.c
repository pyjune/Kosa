#include <stdio.h>

int a[] = {1,2,3};
int p[3];

void npir(int n, int k);
void npir2(int n, int k, int m);

int main(void) {
	
	//npir(0, 3);
	npir2(0, 3, 5);
	
	return 0;
}
void npir2(int n, int k, int m)
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
		for(int i = 1; i <= m; i++)
		{
			p[n] = i;
			npir2(n + 1, k, m);
		}
	}
}
void npir(int n, int k)
{
	if( n == k )
	{
		for(int i = 0; i < k; i++)
		{
			printf("%c ", p[i]);
		}
		printf("\n");
	}
	else
	{
		for(int i = 'a'; i <= 'z'; i++)
		{
			p[n] = i;
			npir(n + 1, k);
		}
	}
}
