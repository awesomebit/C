///////////////////////////////////////////
//문제 번호 : [TST]그래프 칠하기
///////////////////////////////////////////
#if 0
#include <stdio.h>

int N;	//노드 수
int M;	//색상 수
int a[12 + 10][12 + 10];
int chk[12 + 10];
int s[12 + 10];
int cnt = 1;

int Check(int n, int color)
{
	int i;
	for (i = 1; i < n; i++)
	{
		if (a[n][i] == 1 && s[i] == color)
		{
			return 0;
		}
	}
}

int DFS(int n)
{
	// 종료, 성공 조건.
	if (n > N)
	{
		return 1;
	}

	int i;
	for (i = 1; i <= M; i++)
	{
		// i 색깔을 이미 칠했다면 continue 조건.
		if (Check(n, i) == 0) continue;

		// 색깔 목록을 s배열에 저장.
		s[n] = i;
		if (DFS(n + 1) == 1) return 1;
	}

	//for문을 다 돌고 나왔으면 색칠하는데 실패했다는 것.
	return 0;
}

void main(void)
{
	scanf("%d %d", &N, &M);
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	if (DFS(1) == 0) printf("-1");
	else
	{
		for (i = 1; i <= N; i++)
		{
			printf("%d ", s[i]);
		}
	}
}
#endif