#include <stdio.h>

int a[] = {1, 2, 3, 4, 5};
int used[5];
int p[3];

void npr(int n, int k, int m);

int main(void) 
{
	npr( 0, 3, 5);	
	return 0;
}

void npr(int n, int k, int m)
{
	if(n == k)
	{
		for( int i = 0; i < k; i++)
		{
			printf("%d ", p[i]);
		}
		printf("\n");
	}
	else
	{
		for(int i = 0; i < m; i++)
		{
			if( used[i] == 0) // a[i]를 사용하지 않았으면 
			{
				used[i] = 1; // 사용했음으로 표시.. 
				p[n] = a[i];
				npr( n + 1, k, m );
				used[i] = 0; // 다른 자리에서 사용할 수 있도록 함. 
			}
		}
	}
}
