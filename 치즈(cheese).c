////////////////////////////////////////////////
//문제 번호 : [TST] 치즈(cheese)
////////////////////////////////////////////////
#if 01
#include <stdio.h>

#define INF 0x7FFFFFF;

typedef struct st
{
	int i, j, d;
}SET;

SET Q[1000*1000+10];

int H, W, N;
char a[1000 + 10][1000 + 10];
int chk[1000 + 10][1000 + 10];
int ii, jj;
int sol = 0;
int wp, rp;
char num = '1';
int cnt = 0;

int ni, nj, nd;
int ti, tj, td;
int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };

void reset(void)
{
	int i, j;
	for (i = 0; Q[i].d != 0; i++)
	{
		Q[i].i = 0;
		Q[i].j = 0;
		Q[i].d = 0;
	}

	for (i = 1; i <= H; i++)
	{
		for (j = 1; j <= W; j++)
		{
			chk[i][j] = 0;
		}
	}
}

int BFS(void)
{
	Q[wp++].d = 0;

	while (wp > rp)
	{
		ti = Q[rp].i;
		tj = Q[rp].j;
		td = Q[rp++].d;

		if (a[ti][tj] == num)
		{
			ii = ti;
			jj = tj;
			break;
		}

		int k;
		for (k = 0; k < 4; k++)
		{
			ni = ti + di[k];
			nj = tj + dj[k];
			nd = td + 1;

			if (ni < 1 || ni > H || nj < 1 || nj > W) continue;
			if (chk[ni][nj] == 1) continue;
			if (a[ni][nj] == 'X') continue;

			chk[ni][nj] = 1;
			Q[wp].i = ni;
			Q[wp].j = nj;
			Q[wp++].d = nd;
		}
	}
	return td;
}

void main(void)
{
	scanf("%d %d %d", &H, &W, &N);

	int i, j;
	for (i = 1; i <= H; i++)
	{
		for (j = 1; j <= W; j++)
		{
			scanf(" %c", &a[i][j]);
			if (a[i][j] == 'S')
			{
				ii = i; 
				jj = j;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		reset();
		wp = 0;
		rp = 0;
		Q[wp].i = ii;
		Q[wp].j = jj;

		sol += BFS();
		num++;
	}

	printf("%d", sol);
}

#endif
