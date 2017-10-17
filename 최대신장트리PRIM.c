///////////////////////////////////////////PRIM
//문제 번호 : [TST]최대신장트리	
///////////////////////////////////////////
#if 0
#include <stdio.h>

int i, j, d;

int a[1000 + 10][1000 + 10];
int sum[1000 + 10];
int chk[1000 + 10];
int sel;

int N, M;
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
			if (sum[i] < a[sel][i])
			{
				sum[i] = a[sel][i];
			}
		}

		int max = 0;
		for (i = 1; i <= N; i++)
		{
			if (chk[i]) continue;
			if (max < sum[i])
			{
				max = sum[i];
				sel = i;
			}
		}
		chk[sel] = 1;
	}
}

void main(void)
{
	scanf("%d %d", &N, &M);
	int k, l;
	int max = 0;
	for (k = 1; k <= M; k++)
	{
		scanf("%d %d %d", &i, &j, &d);
		if (a[i][j] < d)
		{
			a[i][j] = d;
			a[j][i] = d;
		}
	}

	sel = 1;
	chk[sel] = 1;
	sum[sel] = 0;
	PRIM(sel);

	for (k = 1; k <= N+1; k++)
	{
		sol += sum[k];
	}
	
	printf("%d", sol);
}
#endif