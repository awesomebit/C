////////////////////////////////////////////
//퇴사
////////////////////////////////////////////
#if 01
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct st
{
	int T, P;
}SET;
SET Q[15 + 10];
int work[15 + 10];
int N;
int sol;

void inputData(void)
{
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &Q[i].T, &Q[i].P);
	}
	Q[0].T = 1;
}

void DFS(int sum, int day)
{
	// 종료 조건
	// 퇴사일이 넘어가면 상담 불가능
	if (day > N + 1)return;
	if (day == N + 1)
	{
		if (sol < sum) sol = sum;
		return;
	}

	if (sol < sum) sol = sum;

	// 상담을 할 것인지
	work[day] = 1;
	DFS(sum + Q[day].P, day + Q[day].T);
	work[day] = 0;
	// 말 것인지
	DFS(sum, day + 1);
}

int main(void)
{
	inputData();
	DFS(0, 0);
	printf("%d", sol);

	return 0;
}
#endif
