////////////////////////////////////////////////////
//문제 번호 : [TST]자동차경주대회(BASIC2)
////////////////////////////////////////////////////
#if 0
#include <stdio.h>

int D;
int N;
int d[50 + 10];	//인접한 정비소 사이의 거리
int t[50 + 10];	//정비소 별 정비 시간
int sol = 9999;

int DFS(int n, int sum, int dist)
{
	// 가지치기는 맨 위에.
	if (sol <= sum) return;

	// 종료조건.
	if (n > N)
	{
		if (sol > sum)
		{
			sol = sum;
		}
		return;
	}

	// 정비 받는 경우
	DFS(n + 1, sum + t[n], d[n]);
	//정비 받지 않는 경우
	if (dist + d[n] <= D)
	{
		DFS(n + 1, sum, dist + d[n]);
	}
	// 돌아올 필요가 없어서 chk배열도 필요없음.
}

void main(void)
{
	scanf("%d", &D);
	scanf("%d", &N);
	int i;
	for (i = 0; i <= N; i++)
	{
		scanf("%d", &d[i]);
	}
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &t[i]);
	}

	DFS(1, 0, d[0]);
	printf("%d", sol);
}
#endif