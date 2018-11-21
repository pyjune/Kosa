// acmicpc.net 11404번 문제

#include <stdio.h>
#define INF 0x7fffffff
int m[101][101];

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if( i != j )
                m[i][j] = INF;
        }
    }
    for(int i = 0; i < M; i++)
    {
        int n1, n2, w;
        scanf("%d %d %d", &n1, &n2, &w);
        if(m[n1][n2] > w)
            m[n1][n2] = w;
    }
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            if( i != k)
            {
                for(int j = 1; j <= N; j++)
                {
                    if((j != k) && (j != i))
                    {
                        if((m[i][k] != INF)&&(m[k][j]!=INF))
                        {
                            m[i][j] = (m[i][j] > (m[i][k]+m[k][j])?(m[i][k]+m[k][j]):(m[i][j]));
                        }
                    }
                }
            }
        }
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(m[i][j] == INF)
                printf("0 ");
            else
                printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
