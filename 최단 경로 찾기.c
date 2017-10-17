///////////////////////////////////////////다익스트라
//문제 번호 : [TST]최단 경로 찾기
///////////////////////////////////////////
#if 0
#include <stdio.h>
#define INF 0x7fffffff;
int N;
int a[10 + 10][10 + 10];
int cost[10 + 10];
int chk[10 + 10];
int sel;
int sol = 0;

void DIJKSTRA(void)
{
	int k, i;

	for (k = 0; k < N - 1; k++)
	{
		// 해당 sel값에 갈 수 있는 경로들의 cost값들 정리하고,
		for (i = 1; i <= N; i++)
		{
			if (chk[i] || a[sel][i] == 0) continue;
			if (cost[i] > (cost[sel] + a[sel][i]))
			{
				cost[i] = (cost[sel] + a[sel][i]);
			}
		}

		// 그 cost 값들 비교해서 그 경로로 옮겨준다.
		int min = INF;
		for (i = 1; i <= N; i++)
		{
			if (chk[i]) continue;
			if (min > cost[i])
			{
				min = cost[i];
				sel = i;
			}
		}
		chk[sel] = 1;
	}
}

void main(void)
{
	scanf("%d", &N);
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &a[i][j]);
		}
		cost[i] = INF;
	}

	sel = 1;
	chk[1] = 1;
	cost[1] = 0;
	DIJKSTRA();

	printf("%d", cost[N]);
}
#endif