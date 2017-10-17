///////////////////////////////////////////////
//문제 번호 : [TST]퍼킷
///////////////////////////////////////////////
#if 01
#include <stdio.h>

#define ABS(x) (((x) > 0) ? (x) : (-(x)))
#define INF 0x7fffffff;
typedef struct st
{
	int s, b;
}YORI;
YORI q[10 + 2];
int N;
long long int sol = INF;

void DFS(int n, long long int diff, long long int s, long long int b)
{
	if (n > N)
	{
		if (b == 0) return;
		if (sol > diff)
		{
			sol = diff;
		}
		return;
	}

	long long int _s = s * q[n].s;
	long long int _b = b + q[n].b;
	long long int d = ABS(_s - _b);

	DFS(n + 1, d, _s, _b);
	DFS(n + 1, diff, s, b);
}

void main(void)
{
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++)
	{
		scanf("%lld %lld", &q[i].s, &q[i].b);
	}

	DFS(0, 0, 1, 0);
	printf("%lld", sol);
}
#endif
