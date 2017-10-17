////////////////////////////////////////////////////
//문제 번호 : [TST]건물세우기(BASIC)
////////////////////////////////////////////////////
#if 0
#include <stdio.h>

int N;
int arr[15 + 10][15 + 10];
int s[15 + 10];
int chk[15 + 10];
int ps[15 + 10];
int min = 9999;

int DFS(int n, int sum)
{
	if (min < sum) return;
	if (n > N)
	{
		int i;
		if (sum < min)
		{
			for (i = 1; i <= N; i++)
			{
				ps[i] = s[i];
			}
			min = sum;
		}
		return;
	}

	int i, j;
	for (i = 1; i <= N; i++)
	{
		if (chk[i] == 1) continue;

		chk[i] = 1;
		s[n] = i;
		DFS(n + 1, sum + arr[n][i]);
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
			scanf("%d", &arr[i][j]);
		}
	}

	DFS(1, 0);
	printf("%d\n", min);
	for (i = 1; i <= N; i++)
	{
		printf("%d ", ps[i]);
	}
}
#endif