///////////////////////////////////////////PRIM
//문제 번호 : [TST]최소 비용 트리
//////////////////////////////////////////
#if 0
#include <stdio.h>
#define INF 0x7fffffff;
int a[100 + 10][100 + 10];

int cost[100 + 10];
int chk[100+10];
int sel;

int N;
int sol = 0;

int PRIM(int sel)
{
	int i;
	int k;
	for (k = 0; k < N - 1; k++)
	{
		for (i = 1; i <= N; i++)
		{
			if (chk[i] || a[sel][i] == 0) continue;
			if (cost[i] > a[sel][i]) cost[i] = a[sel][i];
		}

		int min = 0x7fffffff;
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
		for (j = 1; j <= i; j++)
		{
			scanf("%d", &a[i][j]);
			a[j][i] = a[i][j];
		}
		cost[i] = INF;
	}
	
	sel = 1;
	chk[1] = 1;
	cost[1] = 0;

	PRIM(sel);

	for (i = 1; i <= N; i++)
	{
		sol += cost[i];
	}
	printf("%d", sol);
}
#endif