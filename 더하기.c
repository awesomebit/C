////////////////////////////////////////////////////
//문제 번호 : [TST] 더하기
////////////////////////////////////////////////////
#if 0
#include <stdio.h>

int T;
int N, K;
int di[20 + 10];
int sol = 0;

int DFS(int n, int sum)
{
	int i, j;
	if (sum > K || sol == 1) return; //	가지치기 조건. 더 효율적.
	if (n > N)
	{	
		if (sum == K)
		{
			// 항상 종료 조건일 때 답을 찾는다.
			return 1;
		}
		return 0;
	}
	
	// 숫자 포함시킬 경우
	if (DFS(n + 1, sum + di[n])) return 1;	// 답을 찾을 때 끝내는 전형적 유형.
	// 포함시키지 않을 경우
	if (DFS(n + 1, sum)) return 1;
	return 0;
}

void main(void)
{
	scanf("%d", &T);
	int i, j;
	while (T--)
	{
		scanf("%d %d", &N, &K);	
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &di[i]);
		}

		if (DFS(1, 0)) printf("YES\n");
		else printf("NO\n");
	}
}
#endif