///////////////////////////////////////////////
//문제 번호 : [TST]현진이의 농장
///////////////////////////////////////////////
#if 01
#include <stdio.h>

int chk[5 + 10][5 + 10];
int di[] = { 0, 0, -1, 1 };
int dj[] = { -1, 1, 0, 0 };
int K;
int sol;

void DFS(int n, int i1, int j1, int i2, int j2)
{
	if (n <= (25 - K) / 2 && i1 == i2 && j1 == j2) return;

	if (n > (25 - K) / 2)
	{
		sol++;
		return;
	}

	int ni1, nj1, ni2, nj2;
	int k, l;
	for (k = 0; k < 4; k++)
	{
		ni1 = i1 + di[k];
		nj1 = j1 + dj[k];

		if (ni1 < 1 || ni1 > 5 || nj1 < 1 || nj1 > 5) continue;
		if (chk[ni1][nj1] == 1) continue;

		for (l = 0; l < 4; l++)
		{
			ni2 = i2 + di[l];
			nj2 = j2 + dj[l];

			if (ni2 < 1 || ni2 > 5 || nj2 < 1 || nj2 > 5) continue;
			if (chk[ni2][nj2] == 1) continue;
				
			chk[ni1][nj1] = 1;
			chk[ni2][nj2] = 1;
			DFS(n + 2, ni1, nj1, ni2, nj2);
			chk[ni2][nj2] = 0;
			chk[ni1][nj1] = 0;
		}
	}
}

void main(void)
{
	scanf("%d", &K);
	int i;
	int y, x;
	for (i = 1; i <= K; i++)
	{
		scanf("%d %d", &y, &x);
		chk[y][x] = 1;
	}

	chk[1][1] = 1;
	chk[5][5] = 1;
	DFS(1, 1, 1, 5, 5);
	printf("%d", sol);
}
#endif
