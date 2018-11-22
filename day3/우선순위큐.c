#include <stdio.h>
int pq[1000000];
int last = 0;

void enq(int n);
int deq(void);

int main(void) 
{
	enq(7);
	enq(4);
	enq(3);
	enq(2);
	enq(8);
	enq(4);
	enq(6);
	enq(9);
	enq(10);
	while(last > 0)
	{
		printf("%d\n", deq());
	}
	return 0;
}

void enq(int n)
{
	int c = ++last;
	int p = c / 2;
	int t;
	pq[last] = n;
	while((c > 1)&&( pq[c] < pq[p] )) // 부모가 있고 자식이 작으면 교환(최소힙) 
	{
		t = pq[p];
		pq[p] = pq[c];
		pq[c] = t;
		c = p;
		p = c / 2;
	}
}

int deq(void)
{
	int p = 1;
	int root = pq[p];
	int t;
	pq[p] = pq[last];
	last--;
	while(1)
	{
		int left = p * 2;
		int right = p * 2 + 1;
		if(last < left) // 자식이 없는 경우 
		{
			break;
		}
		else if( last == left) // 왼쪽 자식만 있는 경우 
		{
			if(pq[left] < pq[p]) // 자식이 더 작으면 
			{
				t = pq[left];
				pq[left] = pq[p];
				pq[p] = t;
			}
			break; 
		}
		else // 양쪽 자식이 있는 경우 
		{
			int c = ((pq[left] < pq[right])?left:right); // 작은 쪽 선택 
			if(pq[c] < pq[p]) // 자식이 더 작으면 교환 
			{
				t = pq[c];
				pq[c] = pq[p]; 
				pq[p] = t;
				p = c; // 자식으로 이동 
			} 
		}
	}
	return root;
}
