///////////////////////////////////////////
//문제 번호 I: [TST]돌다리 건너기(BASIC)
///////////////////////////////////////////
#if 0
#include <stdio.h>

char ch[10 + 10];
char str[2 + 10][30 + 10];
int M, N;
int sol;

void countLen(void)
{
	for (M = 0; ch[M]; M++);
	for (N = 0; str[0][N]; N++);
}

int DFS(int n, int cnt, int p)
{
	if (n > N)
	{
		if (cnt == M)
		{
			sol++;
		}
		return;
	}

	//밟을 때
	//조건
	if (ch[cnt] == str[p][n])
	{
		DFS(n + 1, cnt + 1, !p);
	}

	//밟지 않을 때
	DFS(n + 1, cnt, p);

}

void main(void)
{
	scanf("%s", ch);
	scanf("%s", str[0]);
	scanf("%s", str[1]);
	countLen();

	DFS(0, 0, 0);
	DFS(0, 0, 1);

	printf("%d", sol);
}
#endif