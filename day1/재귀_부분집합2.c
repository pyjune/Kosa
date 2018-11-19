#include <stdio.h>
// 모든 부분집합의 합... 
// 부분 집합의 합이  10인 경우가 있으면 1, 없으면 0 출력... 
// 부분 집합의 합이 10인 경우의 수 
int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int L[10];

void f(int n, int k);
int find(int n, int k, int v);
int find2(int n, int k, int v, int s); // s : n-1까지 부분집합에 포함된 원소의 합 
void find3(int n, int k, int v, int s);
int cnt;

int main(void) 
{
	//f(0, 10);
	//printf("%d\n", find2(0, 10, 56, 0));
	find3(0, 10, 5, 0);
	printf("%d\n", cnt);
	return 0;
}

void find3(int n, int k, int v, int s)
{
	if( s == v)
	{
		cnt++;
	}
	else if( n == k)
	{
		return;
	}
	else
	{
		find3( n + 1, k, v, s); // a[n]이 포함되지 않은  경우.. 
		find3( n + 1, k, v, s + a[n]); //  a[n]이 포함된 경우.. 
	}
}
int find2(int n, int k, int v, int s)
{
	if( s == v)
	{
		return 1;
	}
	else if( n == k)
	{
		return 0;
	}
	else
	{
		if(find2( n + 1, k, v, s)) // a[n]이 포함되지 않은  경우.. 
		{
			return 1;
		}
		if(find2( n + 1, k, v, s + a[n])) //  a[n]이 포함된 경우.. 
		{
			return 1;
		}
		return 0;
	}
}

int find(int n, int k, int v)
{
	if(n == k)
	{
		int s = 0; 
		for(int i = 0; i<k; i++)
		{
			if(L[i]==1)
			{
				s += a[i];
			}
		}
		if( s == v) // 합이 v인 경우 
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		L[n] = 0;
		if(find(n + 1, k, v) == 1)
		{
			return 1;
		}
		L[n] = 1;
		if(find(n + 1, k, v) == 1)
		{
			return 1;
		}
		return 0;
	}
}
void f(int n, int k) // n 접근할 인덱스, k 배열의 크기 
{
	if(n == k)
	{
		int s = 0; 
		for(int i = 0; i<k; i++)
		{
			if(L[i]==1)
			{
				s += a[i];
			}
		}
		printf("%d\n", s); // 모든 부분집합의 합 
	}
	else
	{
		L[n] = 0;
		f(n + 1, k);
		L[n] = 1;
		f(n + 1, k);
	}
}
