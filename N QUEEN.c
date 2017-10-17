///////////////////////////////////////////
//문제 번호 K: [TST]N QUEEN
///////////////////////////////////////////
#if 0
#include <stdio.h>

// 열 확인		chk1[j]
// 대각선 확인	chk2[i+j]
// 대각선 확인2	chk3[i-j+12] .....절대값으로? NONO. 12를 더해서 bias를 주면 됨.

int N;
int chk1[12 + 10];
int chk2[12 + 12 + 10];
int chk3[12 + 12 + 10];
int sol;

void DFS(int n)
{
	int j;
	if (n > N)
	{
		sol++;
		return;
	}
	for (j = 1; j <= N; j++)
	{
		if (chk1[j] || chk2[n + j] || chk3[n - j + 12]) continue;
		chk1[j] = chk2[n + j] = chk3[n -j +12] = 1;
		DFS(n + 1);
		chk1[j] = chk2[n + j] = chk3[n - j + 12] = 0;
	}
}

void main(void)
{
	scanf("%d", &N);
	DFS(1);
	printf("%d", sol);
}
#endif