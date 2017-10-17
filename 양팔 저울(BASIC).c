///////////////////////////////////////////
//문제 번호 U: [TST]양팔저울(BASIC)
///////////////////////////////////////////
#if 0
#include <stdio.h>

int N;          //추의 개수
int w[12 + 10]; //추의 무게
int chk[12 + 10];
int sol = 0;

int T;          //구슬의 개수
int Gi;			//구슬의 무게

int DFS(int n, int L, int R)
{
	if (L == R)
	{
		sol++;
		return;
	}

	if (n > N)
	{
		return;
	}

	chk[n] = 1;
	DFS(n + 1, L + w[n], R);
	chk[n] = 0;

	chk[n] = 1;
	DFS(n + 1, L, R + w[n]);
	chk[n] = 0;

	chk[n] = 1;
	DFS(n + 1, L, R);
	chk[n] = 0;
}

void main(void)
{
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &w[i]);
	}

	chk[1] = 1;
	scanf("%d", &T);
	for (i = 1; i <= T; i++)
	{
		scanf("%d", &Gi);
		sol = 0;
		DFS(1, Gi, 0);
		if (sol > 0) printf("Y ");
		else printf("N ");
	}
}

#endif