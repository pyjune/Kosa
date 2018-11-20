#include <stdio.h>

int a[] = {10, 11, 12, 13, 14, 15};
int tree[16]; 

int makeT(int n, int s, int e); // 노드번호 n, 정보를 가진 구간 s~e(1차원배열의 인덱스)  
int findT(int n, int s, int e, int l, int r);
void changeT(int n, int s, int e, int idx, int diff);

int main(void) 
{
	int idx = 2;
	int n = 5;
	int diff;
	makeT(1, 0, sizeof(a)/sizeof(a[0]) - 1 );
	printf("%d\n", findT(1, 0, sizeof(a)/sizeof(a[0]) - 1, 3, 5));
	//a[2] : 12 -> 5 : diff -7
	diff = n - a[idx];
	a[idx] = n;
	changeT(1, 0, sizeof(a)/sizeof(a[0]) - 1, idx, diff);
	printf("%d\n", findT(1, 0, sizeof(a)/sizeof(a[0]) - 1, 2, 4));
	
	return 0;
}

int findT(int n, int s, int e, int l, int r)
{
	if(( r < s) || ( e < l ))
	{
		return 0;
	}
	else if(( l <= s ) && ( e <= r))
	{
		return tree[n];
	}
	else
	{
		int r1 = findT( n * 2, s, (s + e)/2, l, r);
		int r2 = findT( n * 2 + 1, (s + e)/2 + 1, e, l, r);
		return (r1 + r2);
	}
}

int makeT(int n, int s, int e)
{
	if( s == e ) // leaf node인 경우
	{
		tree[n] = a[s]; // 배열의 값을 저장..
		return tree[n];
	}
	else
	{
		int r1 = makeT( n * 2, s, (s + e) / 2); // 왼쪽자식으로 이동
		int r2 = makeT( n * 2 + 1, (s + e) / 2 + 1, e);
		tree[n] = r1 + r2;
		return tree[n]; 
	}
}

void changeT(int n, int s, int e, int idx, int diff)
{
	int l = s;
	int r = e;
	
	while( l != r ) // leaf가 아니면.. 
	{
		tree[n] += diff;
		if( idx <= ((l + r) / 2)) // 왼쪽 구간에 속하면
		{
			n = n * 2;
			r = (l + r) / 2;
		} 
		else // 오른쪽 구간에 속하면.. 
		{
			n = n * 2 + 1;
			l = (l + r) / 2 + 1;
		}
	}
	tree[n] += diff; // leaf node 처리.. 	
}
