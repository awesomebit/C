////////////////////////////////////////////
//문제 번호 : [TST]저글링 방사능 오염
////////////////////////////////////////////
#if 0
#include <stdio.h>

typedef struct
{
	int i, j, d;
}ZERG;

ZERG Q[100 * 100 + 10];

int wp, rp;
int ni, nj, nd;
int ti, tj, td;

int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };
int a[100 + 10][100 + 10];
int chk[100 + 10][100 + 10];

int N, M;
int n, m;

void print(void)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			printf("%d ", chk[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int BFS(void)
{
	int k;

	Q[wp].i = n;
	Q[wp].j = m;
	Q[wp++].d = 3;
	chk[n][m] = 1;
	a[n][m] = 3;

	while (wp > rp)
	{
		ti = Q[rp].i;
		tj = Q[rp].j;
		td = Q[rp++].d;

		for (k = 0; k < 4; k++)
		{
			ni = ti + di[k];
			nj = tj + dj[k];
			nd = td + 1;

			if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
			if (a[ni][nj] == 0 || chk[ni][nj] != 0) continue;

			Q[wp].i = ni;
			Q[wp].j = nj;
			Q[wp++].d = nd;
			chk[ni][nj] = 1;
			a[ni][nj] = nd;
		}
	}
	return td;
}

void main(void)
{
	scanf("%d %d", &M, &N);     //가로=M, 세로=N
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	scanf("%d %d", &m, &n);     // x좌표=m, y좌표=n

	printf("%d\n", BFS());


	int flag = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			if (a[i][j] == 1) flag++;
		}
	}

	printf("%d", flag);

}
#endif