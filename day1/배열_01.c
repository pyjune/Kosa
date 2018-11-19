#include <stdio.h>

int L[3];

void f(int n, int k);

int main(void) 
{
	f(0, 3);
	return 0;
}
void f(int n, int k) // n 접근할 인덱스, k 배열의 크기 
{
	if(n == k)
	{
		for(int i = 0; i<k; i++)
		{
			printf("%d", L[i]);
		}
		printf("\n");
	}
	else
	{
		L[n] = 0;
		f(n + 1, k);
		L[n] = 1;
		f(n + 1, k);
	}
}
