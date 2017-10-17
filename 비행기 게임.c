////////////////////////////////////////////////
//문제 번호 : [TEST] 비행기 게임
////////////////////////////////////////////////
#if 0
#include <stdio.h>

int T;
char map[13 + 10][5 + 10];
char dmap[13 + 10][5 + 10];
int M, N;

int di[] = { -1, -1, -1 };
int dj[] = { 0, -1, 1 };

int score;

void DFS(int n, int sum, int i, int j, int attack)
{
	if (n >= 13)
	{
		if (score < sum)
		{
			score = sum;
		}
		return;
	}

	int ni, nj;

	int k, l, m;
	for (k = 0; k < 3; k++)
	{
		ni = i + di[k];
		nj = j + dj[k];

		if (ni < 1 || nj < 1 || nj > 5) continue;

		int s = 0;
		int b = 0;
		if (map[ni][nj] == '*') s++;
		else if (map[ni][nj] == 'X') b++;

		if (attack == 1)
		{
			for (l = ni - 4; l <= ni; l++)
			{
				if (l < 1) continue;
				for (m = 1; m <= 5; m++)
				{
					if (map[l][m] == '*') continue;
					map[l][m] = '0';
				}
			}
			DFS(n + 1, sum + s * 10, ni, nj, 0);
			for (l = ni - 4; l <= ni; l++)
			{
				if (l < 1) continue;
				for (m = 1; m <= 5; m++)
				{
					map[l][m] = dmap[l][m];
				}
			}
			DFS(n + 1, sum + s * 10 - b * 7, ni, nj, 1);
		}
		else
		{
			DFS(n + 1, sum + s * 10 - b * 7, ni, nj, 0);
		}
	}
}

void main(void)
{
	scanf("%d", &T);
	int i, j;
	int k;
	for (k = 1; k <= T; k++)
	{
		for (i = 1; i <= 13; i++)
		{
			for (j = 1; j <= 5; j++)
			{
				scanf(" %c", &map[i][j]);
				dmap[i][j] = map[i][j];
			}
		}

		score = -1000;
		DFS(1, 0, 13, 3, 1);
		printf("%d\n", score);
	}
}
#endif
