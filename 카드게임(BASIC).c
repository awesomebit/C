////////////////////////////////////////////
//문제 번호 A: [TEST] 카드게임 (BASIC)
////////////////////////////////////////////
#if 01
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int N;
int L[26];
int R[26];
int sol;

void inputData(void)
{
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &L[i]);
	for (i = 1; i <= N; i++) scanf("%d", &R[i]);
}

void init(void)
{
	memset(L, 0, sizeof(L));
	memset(R, 0, sizeof(L));
	sol = 0;
}

int smallest(int A, int B)
{
	int i;
	int flag = 0;
	for (i = B; i <= N; i++)
	{
		if (L[A] >= R[i])
		{
			flag = 1;
			return 0;
		}
	}
	if (flag == 0) return 1;
}

int largest(int A, int B)
{
	int i;
	int flag = 0;
	for (i = B; i <= N; i++)
	{
		if (R[A] <= R[i])
		{
			flag = 1;
			return 0;
		}
	}
	if (flag == 0) return 1;
}

void DFS(int nL, int nR, int score)
{
	int l = nL;
	int r = nR;
	int s = score;

	// 종료조건
	if (l > N || r > N)
	{
		if (sol < s) sol = s;
		return;
	}

	// 가지치기 조건

	if (L[l] > R[r])
	{
		// 현재 R카드가 현재 L카드보다 작은 수라면 무조건 현재 R카드 드롭 + 점수
		DFS(l, r + 1, s + R[r]);
		return;
	}
	else
	{
		DFS(l + 1, r + 1, s);
		DFS(l + 1, r, s);
		return;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		inputData();
		
		DFS(0, 0, 0);
		printf("%d\n", sol);
		init();
	}
	return 0;
}
#endif
