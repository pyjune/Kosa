#include <stdio.h>



int A[] = {1, 2, 3, 5, 4, 8, 7, 9};
int B[3];

int find(int n, int k, int v);
void f(int n, int k);

int main(void) 
{
	printf("%d\n", find(0, sizeof(A)/ sizeof(A[0]), 10));
	//f(0, 3);
	return 0;
}
int find(int n, int k, int v)
{
	if(n == k) // 배열을 벗어난 경우
	{
		return 0;
	}
	else if( A[n] == v) // 원하는 값을 찾은 경우 
	{
		return 1;
	}
	else
	{
		return find(n + 1, k, v);	
	} 
}

void f(int n, int k) // n 접근할 인덱스, k 배열의 크기 
{
	if(n == k)
	{
		for(int i = 0; i<k; i++)
		{
			printf("%d", B[i]);
		}
		printf("\n");
	}
	else
	{
		B[n] = A[n];
		f(n + 1, k);
	}
}
