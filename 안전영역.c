////////////////////////////////////////////////////
//문제 번호 : [TST]안전 영역
////////////////////////////////////////////////////
#if 0
#include <stdio.h>

int N;
int arr[100 + 10][100 + 10];
int chk[100 + 10][100 + 10];
int chk2[100 + 10][100 + 10];

int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };
int ni, nj;

int count = 0;
int sol = 0;

void reset(void)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			chk2[i][j] = 0;
		}
	}
}

void set(int n)
{
	int i, j, k;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			chk[i][j] = 1;
		}
	}

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			for (k = 1; k <= n; k++)
			{
				if (arr[i][j] == k)
				{
					chk[i][j] = 0;
				}
			}
		}	
	}
}

//FLOOD FILL
int DFS(int y, int x)
{
	int k;
	if (chk2[y][x] == 1) return;
	if (chk[y][x] == 0) return;
	if (y<1 || y>N || x<1 || x>N) return;

	chk2[y][x] = 1;
	
	for (k = 0; k < 4; k++)
	{
		ni = y + di[k];
		nj = x + dj[k];
		DFS(ni, nj);
	}
}

void main(void)
{
	scanf("%d", &N);
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	// max 높이 구하기.
	int max = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
			}
		}
	}

	int h;
	for (h = 1; h <= max; h++)
	{
		set(h);
		reset();
		count = 0;
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (chk[i][j] == 1 && chk2[i][j] == 0)
				{
					count++;
					DFS(i, j);
				}
			}
		}
		if (sol < count) sol = count;
	}

	printf("%d", sol);


}
#endif