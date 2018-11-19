#include <stdio.h>

int batt[10];
int minV;
// n 정류장, k 종점, e 남은 에너지, s 교환횟수 
void find(int n, int k, int e, int s); 

int main(void) 
{
	int T;
	
	//freopen("input.txt", "r", stdin); // 입력데이터를 파일에서 읽기
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		int N;
		minV = 10; // 교환횟수가 정류장 수를 초과할 수 없으므로 
		scanf("%d", &N);
		for(int i = 1; i < N; i++) // N번 종점은 제외 
		{
			scanf("%d", &batt[i]);
		}
		
		//find(1, N, 0, 0);// 1번 정류장부터 전체 교환횟수에 포함 
		find(2, N, batt[1] - 1, 0); // 1번 정류장의 교환은 제외.. 
		printf("#%d %d\n", tc, minV);
	}
	return 0;
}

void find(int n, int k, int e, int s)
{
	if( n == k ) // 종점에 도착
	{
		if( minV > s)
		{
			minV = s; // 최소 교환횟수 갱신 
		}
	}
	else
	{
		// 통과
		if( e > 0 )
		{
			find( n + 1, k, e - 1, s );
		}
		// 교환 
		find( n + 1, k, batt[n] - 1, s + 1 );
	}
}
