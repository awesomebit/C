///////////////////////////////////////////
//문제 번호 D: [TST]자동차경주대회(BASIC2)
///////////////////////////////////////////
#if 0
#include <stdio.h>
#define INF 0x7fffffff;

int max_dist;
int N;
int d[51 + 10];
int a[50 + 10];
int min = INF;

int DFS(int n, int sum, int p)
{
	if (min <= sum) return;

	// 정비소 다 세면 종료조건.
	if (n > N)
	{
		if (min > sum) min = sum;
		return;
	}

	// 정비소를 들린다.
	DFS(n + 1, sum + a[n], d[n]);
	
	// 정비소를 들리지 않는다.
	if (p + d[n] <= max_dist)
	{
		DFS(n + 1, sum, p + d[n]);
	}
}

void main(void)
{
	scanf("%d", &max_dist);
	scanf("%d", &N);
	int i;
	for (i = 0; i <= N; i++)
	{
		scanf("%d", &d[i]);
	}
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
	}

	DFS(1, 0, d[0]);

	printf("%d", min);

}
#endif