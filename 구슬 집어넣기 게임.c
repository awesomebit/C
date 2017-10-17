////////////////////////////////////////////////
//문제 번호 : [TEST] 구슬 집어넣기 게임
////////////////////////////////////////////////
#if 01
#include <stdio.h>

#define r 0
#define b 1
#define h 2

#define INF 0x7FFFFFFF
typedef struct st
{
	int i, j;
}COORDINATE;

COORDINATE cor[3];

int T;
int R, C;
char a[15 + 10][15 + 10];
int map[15 + 10][15 + 10];

int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };

int sol = INF;
int flag = 0;

int DFS(int n, int cnt, int r_i, int r_j, int b_i, int b_j)
{
	int r_ni, r_nj;
	int b_ni, b_nj;

	if (sol < cnt) return;
	if (r_i == b_i && r_j == b_j) return;
	if (b_i == cor[h].i && b_j == cor[h].j) return;
	if (n > 11) return;

	if (r_i == cor[h].i && r_j == cor[h].j)
	{
		if (sol > cnt)
		{
			sol = cnt;
		}
		return;
	}

	int k;
	for (k = 0; k < 4; k++)
	{
		if (map[r_i + di[k]][r_j + dj[k]] != 1)
		{
			r_ni = r_i + di[k];
			r_nj = r_j + dj[k];
		}
		else
		{
			r_ni = r_i;
			r_nj = r_j;
		}

		if (map[b_i + di[k]][b_j + dj[k]] != 1)
		{
			b_ni = b_i + di[k];
			b_nj = b_j + dj[k];
		}
		else
		{
			b_ni = b_i;
			b_nj = b_j;
		}

		DFS(n + 1, cnt + 1, r_ni, r_nj, b_ni, b_nj);
	}

}

void reset(void)
{
	int i, j;
	for (i = 1; i <= 15; i++)
	{
		for (j = 1; j <= 15; j++)
		{
			map[i][j] = 0;
		}
	}
}

void main(void)
{
	scanf("%d", &T);
	int t, i, j;
	int n = 0;
	for (t = 0; t < T; t++)
	{
		reset();
		scanf("%d %d", &R, &C);
		for (i = 1; i <= R; i++)
		{
			for (j = 1; j <= C; j++)
			{
				scanf(" %c", &a[i][j]);
				if (a[i][j] == '#')
				{
					map[i][j] = 1;
				}
				else if (a[i][j] == 'R')
				{
					cor[r].i = i;
					cor[r].j = j;
				}
				else if (a[i][j] == 'B')
				{
					cor[b].i = i;
					cor[b].j = j;
				}
				else if (a[i][j] == 'H')
				{
					cor[h].i = i;
					cor[h].j = j;
				}
			}
		}

		sol = INF;
		int temp;
		temp = DFS(1, 0, cor[r].i, cor[r].j, cor[b].i, cor[b].j);
		if (sol == INF)
		{
			printf("-1\n");
		}
		else printf("%d\n", sol);

	}
}

#endif
