////////////////////////////////////////////
//문제 번호 : [TST]N QUEEN(BASIC)
////////////////////////////////////////////
#if 0
#include <stdio.h>

int N;
int chk[10 + 10][10+10];
int sol;

int Check(int si, int sj)
{
	int i, j;
	for (i = si; i > 0; i--)
	{
		if (chk[i][sj] == 1) return 0;
	}
	for (i = si, j = sj; i > 0 && j > 0; i--, j--)
	{
		if (chk[i][j] == 1) return 0;
	}
	for (i = si, j = sj; i > 0 && j <= N; i--, j++)
	{
		if (chk[i][j] == 1) return 0;
	}
	return 1;
}

void DFS(int n)
{
	int i;
	if (n > N)
	{
		sol++;
		return;
	}
	for (i = 1; i <= N; i++)
	{
		if (Check(n, i) == 0) continue;
		chk[n][i] = 1;
		DFS(n + 1);
		chk[n][i] = 0;
	}
}

void main(void)
{
	scanf("%d", &N);
	DFS(1);
	printf("%d", sol);
}

#endif