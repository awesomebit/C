///////////////////////////////////////////////
//문제 번호 I: [TST]산림욕
///////////////////////////////////////////////
#if 01
#include <stdio.h>

#define MAX(x, y) (((x)>(y)) ? (x) : (y))
typedef struct st
{
	int i, j, d;
}SET;
SET q[110 * 110 + 10];
int N;
int map[110][110];
int sol;

void function(void)
{
	int i, j;
	int n = 1;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= n; j++)
		{
			int tmp = MAX(map[i-1][j-1], map[i-1][j]);
			map[i][j] += tmp;
			if (sol < map[i][j]) sol = map[i][j];
		}
		n++;
	}
}

int main(void)
{
	scanf("%d", &N);
	int i, j;
	int n = 1;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &map[i][j]);
		}
		n++;
	}
	
	function();
	printf("%d", sol);
}
#endif
