////////////////////////////////////////////
//문제 번호 A: [TEST] 뿌요뿌요
////////////////////////////////////////////
#if 01
#include <stdio.h>
#include <stdlib.h>

int T;
char map[12+5][6+5];
int chk[12+5][6+5];
int count;

void inputData(void)
{
	int i, j;
	for (i = 1; i <= 12; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			scanf(" %c", &map[i][j]);
		}
	}
}

int floodfill(int i, int j, char block)
{
	static int di[] = { -1, 0, 1, 0 };
	static int dj[] = { 0, 1, 0, -1 };
	int ni, nj;
	int k;

	chk[i][j] = 1;
	count++;

	for (k = 0; k < 4; k++)
	{
		ni = i + di[k];
		nj = j + dj[k];

		if (ni < 1 || ni > 12 || nj < 1 || nj > 6) continue;
		if (map[ni][nj] == '.') continue;
		if (map[ni][nj] != block) continue;
		if (chk[ni][nj] == 1) continue;

		floodfill(ni, nj, block);
	}
	return count;
}

void clearChk(void)
{
	int i, j;
	for (i = 1; i <= 12; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			chk[i][j] = 0;
		}
	}
}

void bbuyo(void)
{
	int i, j;
	for (i = 1; i <= 12; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			if (chk[i][j] == 1)
			{
				map[i][j] = '.';
			}
		}
	}
}

int check(int i, int j, char block)
{
	// 4개 이상 연결되어있으면 터짐
	if (floodfill(i, j, block) >= 4)
	{
		bbuyo();
		clearChk();
		return 1;
	}
	else
	{
		clearChk();
		return 0;
	}
}

int fall_(int j)
{
	int i, k, ii;

	//회전수 11번
	for (k = 1; k < 12; k++)
	{
		//밑에서부터 '.'인 경우 그 위에 블록 전부 내리기
		for (i = 12; i > 1; i--)
		{
			//'.'인 경우
			if (map[i][j] == '.')
			{
				// 그 위에 블록 전부 내려야함
				for (ii = i; ii > 1; ii--)
				{
					map[ii][j] = map[ii - 1][j];
				}
				map[1][j] = '.';
			}
		}
	}
}

void fall(void)
{
	int i, j;
	int cnt = 0;
	for (j = 1; j <= 6; j++)
	{
		// 열마다 fall 구현
		fall_(j);
	}
}

int solve(void)
{
	int i, j;
	int sol = 0;
	int flag = 0;

	int k;
	// 맵 검색
	for (;;)
	{
		// 뿌요 검색
		flag = 0;
		for (i = 1; i <= 12; i++)
		{
			for (j = 1; j <= 6; j++)
			{
				if (map[i][j] != '.' && chk[i][j] == 0)
				{
					count = 0;
					if (check(i, j, map[i][j]) == 1) flag = 1;
				}
			}
		}
		if (flag == 0) return sol;
		sol++;
		// 뿌요가 떨어진다
		fall();
	}
	return -1;
}

int main(void)
{
	int t;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		inputData();
		printf("%d\n", solve());
	}

	return 0;
}
#endif
