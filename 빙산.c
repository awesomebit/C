///////////////////////////////////////////////
//문제 번호 : [TST]빙산
///////////////////////////////////////////////
#if 01
#include <stdio.h>

int N, M;
int map[300 + 10][300 + 10];
int chk[300 + 10][300 + 10];
int t_map[300 + 10][300 + 10];
int cnt;
int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };
int year;

void clearChk(void)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			chk[i][j] = 0;
		}
	}
}

void floodfill(int i, int j)
{
	chk[i][j] = 1;

	int ni, nj;
	int k;
	for (k = 0; k < 4; k++)
	{
		ni = i + di[k];
		nj = j + dj[k];

		if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
		if (map[ni][nj] == 0 || chk[ni][nj] == 1) continue;

		floodfill(ni, nj);
	}
}

int melt(int i, int j)
{
	int count = 0;
	int ni, nj;
	int k;
	for (k = 0; k < 4; k++)
	{
		ni = i + di[k];
		nj = j + dj[k];

		if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
		if (map[ni][nj] != 0) continue;

		count++;
	}

	return count;
}

void main(void)
{
	scanf("%d %d", &N, &M);
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf("%d ", &map[i][j]);
		}
	}

	while (1)
	{
		cnt = 0;

		// Chk배열 클리어
		clearChk();

		// floodfill 함수로 빙산 갯수 체크
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				if (map[i][j] != 0 && chk[i][j] == 0)
				{
					cnt++;
					floodfill(i, j);
				}
			}
		}

		// melt 함수로 빙산 녹이기
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				if (map[i][j] == 0) continue;
				t_map[i][j] = melt(i, j);
			}
		}

		// map배열에 t_map배열로 조정
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				if (map[i][j] == 0) continue;
				map[i][j] -= t_map[i][j];
				if (map[i][j] < 0) map[i][j] = 0;
			}
		}

		if (cnt > 1)
		{
			printf("%d", year);
			break;
		}
		if (cnt == 0)
		{
			printf("0");
			break;
		}
		year++;
	}
}
#endif
