///////////////////////////////////////////
//문제 번호 W: [LAB]계단 오르기(BASIC)
///////////////////////////////////////////
#if 0
#include <stdio.h>

int N;
int a[50 + 10];
int max = 0;

int DFS(int n, int sum, int cnt)
{
	if (n < 1)
	{
		if (max < sum) max = sum;
		return;
	}

	// 반대로 위에서 아래로 내려가는 걸로 풀면 더 편하다 (마지막 계단은 꼭 밟아야하므로)
	// 연속해서 2번 이상 밟으면 밟지 못한다.
	if (cnt < 2)
	{
		DFS(n - 1, sum + a[n], cnt + 1);
	}
	// 한번도 밟지 않았으면 밟을 수 있다. 이 때도 조건은 필요.
	if (cnt > 0)
	{
		DFS(n - 1, sum, 0);
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

	// 이미 마지막 계단을 한번 밟고 시작.
	DFS(N - 1, a[N], 1);
	printf("%d", max);
}

#endif