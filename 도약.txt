///////////////////////////////////////////////
//문제 번호 A: [TST] 도약
///////////////////////////////////////////////
#if 01
#include <stdio.h>

int N;
int a[1000 + 10];
int sol;

void DFS(int n, int d, int cnt, int dist)
{
	if (n > 2)
	{
		if (cnt == 2)
		{
			sol++;
		}
		return;
	}

	int k;
	for (k = d + 1; k <= N; k++)
	{
		if (cnt == 1 && a[k] - a[d] >= dist && a[k] - a[d] <= dist*2)
		{
			DFS(n + 1, k, cnt + 1, a[k] - a[d]);
		}
		else if (cnt == 0)
		{
			DFS(n + 1, k, cnt + 1, a[k] - a[d]);
		}
	}
}

void sort(void)
{
	int i, j;
	int temp;
	for (i = 1; i < N; i++)
	{
		for (j = i; j <= N; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void main(void)
{
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
	}

	sort();

	for (i = 1; i <= N; i++)
	{
		DFS(1, i, 0, 0);
	}

	printf("%d", sol);
}
#endif
