///////////////////////////////////////////
//1949. [모의 SW 역량테스트] 등산로 조성
///////////////////////////////////////////
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int height;
	int i, j;
}INFO;
INFO Q[10 * 10 * 10];
int N, K;
int map[10][10];
int tmap[10][10];
int D[10][10];
int n = 1;
int sol;
int max;

//int comp(const INFO * p1, const INFO * p2)
//{
//	return p1->height - p2->height;
//}

void sort(void)
{
	INFO tmp;
	int i, j;
	for (i = 1; i < N*N; i++)
	{
		for (j = i + 1; j <= N*N; j++)
		{
			if (Q[i].height > Q[j].height)
			{
				tmp = Q[i];
				Q[i] = Q[j];
				Q[j] = tmp;
			}
		}
	}
}

void inputData(void)
{
	scanf("%d %d", &N, &K);
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			tmap[i][j] = map[i][j];
			D[i][j] = 1;
			Q[n].i = i;
			Q[n].j = j;
			Q[n++].height = map[i][j];
			if (max < map[i][j]) max = map[i][j];
		}
	}
}

void reset(void)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			tmap[i][j] = map[i][j];
			D[i][j] = 1;
		}
	}
}

void findLIS(void)
{
	static int di[] = { -1, 0, 1, 0 };
	static int dj[] = { 0, 1, 0, -1 };
	int ni, nj;

	int y, x;
	int i, j, k, l;

	for (y = 1; y <= N; y++)
	{
		for (x = 1; x <= N; x++)
		{
			// K 만큼 깎는 조건 실행
			for (l = 1; l <= K; l++)
			{
				tmap[y][x] -= l;
				if (tmap[y][x] < 0) tmap[y][x] = 0;
				//////////////////////////////////////////////Dynamic Programming
				for (i = 2; i <= N*N; i++)
				{
					for (j = 1; j <= i; j++)
					{
						for (k = 0; k < 4; k++)
						{
							ni = Q[j].i + di[k];
							nj = Q[j].j + dj[k];

							if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
							if (tmap[ni][nj] <= tmap[Q[j].i][Q[j].j]) continue;

							if (D[ni][nj] < D[Q[j].i][Q[j].j] + 1)
							{
								D[ni][nj] = D[Q[j].i][Q[j].j] + 1;
								if (sol < D[ni][nj] && map[ni][nj] == max)
								{
									sol = D[ni][nj];
								}
							}
						}
					}
				}
				/////////////////////////////////////////////////////////////////
				//initalization
				reset();
			}
		}
	}
}

void init(void)
{
	N = 0, K = 0;
	sol = 0;
	n = 1;
	max = 0;
	memset(Q, 0, sizeof(Q));
	memset(D, 1, sizeof(D));
	memset(map, 0, sizeof(map));
	memset(tmap, 0, sizeof(tmap));
}

int main(void)
{
	int cnt = 1;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		inputData();
		//qsort(&Q[0], n, sizeof(INFO), comp);
		sort();
		findLIS();
		printf("#%d %d\n", cnt++, sol);

		init();
	}

	return 0;
}
#endif
