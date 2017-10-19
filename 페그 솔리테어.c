///////////////////////////////////////
//문제 번호 B: [TEST] 페그 솔리테어
///////////////////////////////////////
#if 01
#include <stdio.h>

char map[5 + 2][9 + 2];
int cnt;
int sol;

void inputData(void)
{
	cnt = 0;
	int i, j;
	for (i = 1; i <= 5; i++)
	{
		scanf("%s", &map[i][1]);
		for (j = 1; j <= 9; j++)
		{
			if (map[i][j] == 'o') cnt++;
		}
	}
}

void DFS(int n)
{
	static int di[] = { 0, 0, 1, -1 };
	static int dj[] = { 1, -1, 0, 0 };
	char nd;
	char nnd;
	int k;
	int i, j;
	int flag;

	// DFS
	flag = 0;
	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			if (map[i][j] == 'o')
			{
				for (k = 0; k < 4; k++)
				{
					nd = map[i + di[k]][j + dj[k]];
					nnd = map[i + di[k] + di[k]][j + dj[k] + dj[k]];

					if (nd == 'o' && nnd == '.')
					{
						flag = 1;
						map[i][j] = '.';
						map[i + di[k]][j + dj[k]] = '.';
						map[i + di[k] + di[k]][j + dj[k] + dj[k]] = 'o';
						DFS(n - 1);
						map[i][j] = 'o';
						map[i + di[k]][j + dj[k]] = 'o';
						map[i + di[k] + di[k]][j + dj[k] + dj[k]] = '.';
					}
				}
			}
		}
	}
	if (flag == 0)
	{
		if (sol > n) sol = n;
	}

	return;
}
	
int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		inputData();
		sol = 0x7fffffff;
		DFS(cnt);
		printf("%d %d\n", sol, cnt - sol);
	}

	return 0;
}
#endif
