#include <stdio.h>

int M, N, H;
int a[110][110][110];
int chk[110][110][110];


int function(int k, int i, int j, int num)
{
	int dk[] = { 1, -1, 0, 0, 0, 0 };
	int di[] = { 0, 0, -1, 1, 0, 0 };
	int dj[] = { 0, 0, 0, 0, -1, 1 };
	int nk, ni, nj;

	int l;
	for (l = 0; l < 6; l++)
	{
		nk = k + dk[l];
		ni = i + di[l];
		nj = j + dj[l];
		
		if (nk < 1 || nk > H || ni < 1 || ni > N || nj < 1 || nj > M) continue;
		if (chk[nk][ni][nj] == 1) continue;
		
		chk[nk][ni][nj] = 1;
		a[nk][ni][nj] = num;
	}
	

}

void print(void)
{
	int i, j, k;
	for (k = 1; k <= H; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				printf("%3d ", a[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
}

void main(void)
{
	scanf("%d %d %d", &M, &N, &H);
	int i, j, k;
	for (k = 1; k <= H; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				scanf("%d", &a[k][i][j]);
			}
		}
	}

	for (k = 1; k <= H; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				if (a[k][i][j] == 1 || a[k][i][j] == -1) chk[k][i][j] = 1;
			}
		}
	}

	int rot;
	int n = 1;
	for (rot = 0; rot < 100; rot++)
	{
		for (k = 1; k <= H; k++)
		{
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= M; j++)
				{
					if (a[k][i][j] == n)
					{
						function(k, i, j, n+1);
					}
				}
			}
		}
		n++;
	}

	int empty = 0;
	int sol = 0;
	for (k = 1; k <= H; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				if (a[k][i][j] == 0)
				{
					empty = 1;
				}
				if (a[k][i][j] > sol) sol = a[k][i][j];
			}
		}
	}

	//print();

	if (empty == 1) printf("-1");
	else printf("%d", sol-1);

}
