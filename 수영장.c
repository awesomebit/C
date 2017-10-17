///////////////////////////////////////////////
//1952. [모의 SW 역량테스트] 수영장
///////////////////////////////////////////////
#if 01
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int T;
// 1일, 1달, 3달, 1년 이용권
int p1, p2, p3, p4;
int schedule[12 + 2][3];
#define INF 0x7fffffff
int sol = INF;

void inputData(void)
{
	int i;
	scanf("%d %d %d %d", &p1, &p2, &p3, &p4);
	for (i = 1; i <= 12; i++)
	{
		scanf("%d", &schedule[i][1]);
		if (schedule[i][1] > 0) schedule[i][0] = 1;
	}
}

void DFS(int n, int cost)
{
	if (n > 12)
	{
		if (cost < sol) sol = cost;
		return;
	}
	
	int k, flag = 0;
	int c1, c2, c3;
	c1 = schedule[n][1] * p1;
	c2 = schedule[n][0] * p2;
	for (k = 0; k < 3; k++)
	{
		if (schedule[n + k][0] == 1)
		{
			flag = 1; 
			break;
		}
	}
	c3 = flag * p3;

	DFS(n + 1, cost + c1);
	DFS(n + 1, cost + c2);
	DFS(n + 3, cost + c3);
}

int main(void)
{
	int cnt = 1;

	scanf("%d", &T);
	while (T--)
	{
		memset(&schedule[0][0], 0, sizeof(int[14][14]));
		inputData();
		sol = p4;
		DFS(1,0);

		printf("#%d %d\n", cnt++,  sol);
	}

	return 0;
}
#endif
