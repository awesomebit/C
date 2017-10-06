///////////////////////////////////////////////
//문제 번호 B: [TST]등산로 찾기
///////////////////////////////////////////////
#if 01
#include <stdio.h>

#define INF 0x7fffffff

typedef struct st
{
	int i, j;
}MAP;

MAP q[1000 * 1000 + 10];

int N;
int y, x;	// 산 정상 좌표

int map[100 + 10][100 + 10];
int sel[100 + 10][100 + 10];

int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };
int wp, rp;

int diff(int x, int y)
{
	return (x - y) >= 0 ? (x - y) : -(x - y);
}

void BFS(void)
{
	int ti, tj;
	int ni, nj;
	int tmpdist;
	int tmpdiff;

	int i, j;
	for (i = 0; i <= N + 1; i++)
	{
		for (j = 0; j <= N + 1; j++)
		{
			if (map[i][j] == 0)
			{
				q[wp].i = i;
				q[wp++].j = j;
			}
		}
	}

	while (wp > rp)
	{
		ti = q[rp].i;
		tj = q[rp++].j;

		int k;
		for (k = 0; k < 4; k++)
		{
			ni = ti + di[k];
			nj = tj + dj[k];

			if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
			if (map[ni][nj] == 0) continue;

			tmpdiff = diff(map[ti][tj], map[ni][nj]);
			if (map[ti][tj] == map[ni][nj]) tmpdist = 0;
			else if (map[ti][tj] < map[ni][nj]) tmpdist = tmpdiff*tmpdiff;
			else if (map[ti][tj] > map[ni][nj]) tmpdist = tmpdiff;

			if (sel[ni][nj] <= sel[ti][tj] + tmpdist) continue;

			q[wp].i = ni;
			q[wp++].j = nj;
			sel[ni][nj] = sel[ti][tj] + tmpdist;
		}
	}
	return;
}

void main(void)
{
	scanf("%d", &N);

	scanf("%d %d", &y, &x);
	int i, j;
	int n = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			sel[i][j] = INF;
		}
	}

	BFS();

	printf("%d", sel[y][x]);
}
#endif
