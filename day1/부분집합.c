#include <stdio.h>

int a[] = {1,2,3};
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
			if(L[i]==1)
			{
				printf("%d ", a[i]); // i번 원소가 포함된 부분집합 
			}
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
