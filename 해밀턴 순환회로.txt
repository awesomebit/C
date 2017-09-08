////////////////////////////////////////////////////
//문제 번호 : [TST]해밀턴 순환회로
////////////////////////////////////////////////////
#if 0
#include <stdio.h>

int N;
int arr[12 + 10][12 + 10];
int chk[12 + 10];
int s[12 + 10];
int ps[12 + 10];
int min = 0x7fffffff;
int sol = 0;

int DFS(int n, int sum, int dir)
{
	int k;
	if (sum > min) return;
	if (n >= N)
	{ 
		if (arr[dir][1] == 0) return;
		sum += arr[dir][1];
		if (min > sum)
		{
			min = sum;
		}
		return;
	}
	chk[1] = 1;
	for (k = 1; k <= N; k++)
	{
		if (chk[k] == 1) continue;
		if (arr[dir][k] == 0) continue;

		chk[k] = 1;
		DFS(n + 1, sum + arr[dir][k], k);
		chk[k] = 0;
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

	DFS(1, 0, 1);

	printf("%d", min);
}
#endif