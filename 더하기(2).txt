////////////////////////////////////////////
//문제 번호 : [TST] 더하기
////////////////////////////////////////////
#if 0
#include <stdio.h>

int T;
int N, K;
int di[20 + 10];
int sol = 0;

int DFS(int n, int sum)
{
	if (n > N)
	{	
		if (sum == K)
		{
			sol = 1;
		}
		return;
	}

	DFS(n + 1, sum + di[n]);
	DFS(n + 1, sum);
}

void main(void)
{
	int i, k;
	scanf("%d", &T);
	
	while (T--)
	{
		scanf("%d %d", &N, &K);
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &di[i]);
		}
		sol = 0;
		DFS(1, 0);
		if (sol) printf("YES\n");
		else printf("NO\n");
	}
}
#endif