///////////////////////////////////////////
//문제 번호 : [TST]최대신장트리
///////////////////////////////////////////
#if 0
#include <stdio.h>

typedef struct
{
	int s, e, d;
}SET;

SET Q[1000 + 10];

int chk[1000 + 10];
int ns, ne, nd;
int sol = 0;
int N, M;

int DFS(int n, int sum)
{
	if (n == N)
	{
		printf("sum=%d\n", sum);
		if (sol < sum) sol = sum;
		return;
	}

	int k;
	for (k = 1; k <= M; k++)
	{
		ns = Q[k].s;
		ne = Q[k].e;
		nd = Q[k].d;

		if (ns == n && chk[ne] == 0)
		{
			chk[ns] = 1;
			DFS(n + 1, sum + nd);
			chk[ns] = 0;
		}
		//chk[ne] = 0;
		if (ne == n && chk[ns] == 0)
		{
			chk[ne] = 1;
			DFS(n + 1, sum + nd);
			chk[ne] = 0;
		}
	}
}

void main(void)
{
	scanf("%d %d", &N, &M);
	int i;
	for (i = 1; i <= M; i++)
	{
		scanf("%d %d %d", &Q[i].s, &Q[i].e, &Q[i].d);
	}

	chk[1] = 1;
	for (i = 1; i <= N; i++)
	{
		DFS(i, 0);
	}
	printf("%d", sol);
}
#endif