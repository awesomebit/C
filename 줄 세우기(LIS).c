//////////////////////////////////////////
//문제 번호 L: [TST]줄 세우기
//////////////////////////////////////////
#if 01
#include <stdio.h>

int N;
int num[200 + 10];
int D[200 + 10];
int path[200 + 10];

void inputData(void)
{
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &num[i]);
	}
}

void printPath(int idx)
{
	// 추적한 path를 역으로 출력하는 재귀함수.
	if (idx == 0) return;
	printPath(path[idx]);
	printf("%d ", num[idx]);
}

int findLIS(void)
{
	int n, k;
	int maxlen = 0;
	int lastidx;
	num[0] = 0;
	D[0] = 0;

	for (n = 1; n <= N; n++)
	{
		for (k = 0; k < n; k++)
		{
			if (num[k] < num[n] && D[n] < D[k] + 1)
			{
				D[n] = D[k] + 1;
				path[n] = k;
			}
		}
		if (maxlen < D[n])
		{
			maxlen = D[n];
			lastidx = n;
		}
	}

	printPath(lastidx);
	printf("\n");

	return maxlen;
}

void main(void)
{
	inputData();
	printf("%d", N - findLIS());
}
#endif
