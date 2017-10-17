//////////////////////////////////////////
//문제 번호 O: [TST] 전깃줄(초)
//////////////////////////////////////////
#if 01
#include <stdio.h>
#include <stdlib.h>

int N;
typedef struct st
{
	int a, b;
}POLL;
POLL q[110];
int D[110];

void inputData(void)
{
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &q[i].a, &q[i].b);
	}
}

int comp(const POLL* p1, const POLL* p2)
{
	// 전깃줄A 기준으로 정렬
	return p1->a - p2->a;
}

int findLIS(void)
{
	int n, k;
	int maxlen = 0;

	for (n = 1; n <= N; n++)
	{
		for (k = 0; k < n; k++)
		{
			if (q[n].b > q[k].b && D[n] < D[k] + 1)
			{
				D[n] = D[k] + 1;
			}
			if (maxlen < D[n]) maxlen = D[n];
		}
	}
	return maxlen;
}

int main(void)
{
	inputData();
	qsort(&q[1], N, sizeof(POLL), comp);
	printf("%d", N - findLIS());

	return 0;
}
#endif
