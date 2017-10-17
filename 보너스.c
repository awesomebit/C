///////////////////////////////////////////
//문제 번호 L: [TST]보너스
///////////////////////////////////////////
#if 01
#include <stdio.h>

int N;	//직원수
int M;	//상하관계 수
int high;
int low;
int a[100 + 10][100 + 10];
int bonus[10 + 10];
int chk[100 + 10];
int sol[100 + 10];

void sort(void)
{
	int i, j;
	int temp;
	for (i = 1; i <= N-1; i++)
	{
		for (j = i; j <= N; j++)
		{
			if (bonus[i] < bonus[j])
			{
				temp = bonus[i];
				bonus[i] = bonus[j];
				bonus[j] = temp;
			}
		}
	}
}

// n번 직원이 m원을 받을 수 있는 지 체크 함수.
int Check(int n, int m)
{
	int i;
	// 이미 보너스를 받은 직원들까지만 확인
	for (i = 1; i < n; i++)
	{
		// 부하직원
		if (a[n][i] == 1 && m <= sol[i])
		{
			return 0;
		}
		// 상사
		if (a[i][n] == 1 && m >= sol[i])
		{
			return 0;
		}
	}
}

int DFS(int n)
{
	// n은 직원번호.
	if (n > N)
	{
		return 1;
	}

	int k;
	for (k = 1; k <= N; k++)
	{
		if (chk[k] || Check(n, bonus[k]) == 0) continue;
		chk[k] = 1;
		sol[n] = bonus[k];
		if (DFS(n + 1) == 1) return 1;
		chk[k] = 0;
	}
	return 0;
}

void main(void)
{
	scanf("%d %d", &N, &M);
	int i,j;
	for (i = 1; i <= M; i++)
	{
		scanf("%d %d", &high, &low);
		a[high][low] = 1;
	}
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &bonus[i]);
	}

	sort();

	if (DFS(1) == 1)
	{
		for (i = 1; i <= N; i++)
		{
			printf("%d ", sol[i]);
		}
	}
	else printf("-1");
}

#endif