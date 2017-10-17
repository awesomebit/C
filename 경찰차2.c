///////////////////////////////////////
//문제 번호 Z: [TST]경찰차2
///////////////////////////////////////
#if 01
#include <stdio.h>

#define INF 0x7FFFFFFF;
#define ABS(x) ((x)>0 ? (x) : -(x))

typedef struct st
{
	int i, j;
}SET;

SET Q[20 + 10];

int N, W;
int sol = INF;

int ii0;
int jj0;
int ii1;
int jj1;

void DFS(int n, int sum, int i_0, int j_0, int i_1, int j_1)
{
	if (n > W)
	{
		if (sol > sum)
		{
			sol = sum;
		}
		return;
	}

	DFS(n + 1, sum + ABS(Q[n].i - i_0) + ABS(Q[n].j - j_0), Q[n].i, Q[n].j, i_1, j_1);
	DFS(n + 1, sum + ABS(Q[n].i - i_1) + ABS(Q[n].j - j_1), i_0, j_0, Q[n].i, Q[n].j);
}

void main(void)
{
	scanf("%d %d", &N, &W);
	int k;
	for (k = 1; k <= W; k++)
	{
		scanf("%d %d", &Q[k].j, &Q[k].i);
	}

	ii0 = 1;
	jj0 = 1;
	ii1 = N;
	jj1 = N;

	DFS(1, 0, ii0, jj0, ii1, jj1);
	
	printf("%d", sol);
}
#endif

