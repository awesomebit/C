////////////////////////////////////////////
//문제 번호 : [TST]건물세우기(BASIC)
////////////////////////////////////////////
#if 0
#include <stdio.h>

int N;
int a[15 + 10][15 + 10];
int chk[15 + 10];
int ps[15 + 10];
int s[15 + 10];
int sol = 0x7fffffff;

int DFS(int n, int sum)
{
	if (sol < sum) return;
	if (n > N)
	{
		int i;
		if (sol > sum)
		{
			for (i = 1; i <= N; i++)
			{
				ps[i] = s[i];
			}
			sol = sum;
		}
		
		return;
	}

	int i;
	for (i = 1; i <= N; i++)
	{
		if (chk[i] == 1) continue;

		s[n] = i;
		chk[i] = 1;
		DFS(n + 1, sum + a[n][i]);
		chk[i] = 0;
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
			scanf("%d", &a[i][j]);
		}
	}

	DFS(1, 0);
	printf("%d\n", sol);
	for (i = 1; i <= N; i++)
	{
		printf("%d ", ps[i]);
	}



}
#endif