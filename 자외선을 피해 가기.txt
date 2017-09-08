///////////////////////////////////////////
//문제 번호 : [TST]자외선을 피해 가기
///////////////////////////////////////////
#if 01
#include <stdio.h>
#define INF 0x7fffffff;

typedef struct
{
	int i, j;
}SUN;

SUN Q[100 * 100 * 100 + 10];

int N;
int a[110][110];
int s[110][110];

int wp, rp;
int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };

//중복이 허용되는 BFS.
int BFS(void)
{
	int ni, nj, nd;
	int ti, tj, td;

	Q[wp].i = 1;
	Q[wp++].j = 1;
	s[1][1] = a[1][1];

	while (wp > rp)
	{
		ti = Q[rp].i;
		tj = Q[rp++].j;

		int k;
		for (k = 0; k < 4; k++)
		{
			ni = ti + di[k];
			nj = tj + dj[k];

			if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
			if (s[ni][nj] < s[ti][tj] + a[ni][nj]) continue;
			
			s[ni][nj] = s[ti][tj] + a[ni][nj];
			Q[wp].i = ni;
			Q[wp++].j = nj;
		}
	}
	return s[N][N];
}

void main(void)
{
	scanf("%d", &N);
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%1d", &a[i][j]);
			s[i][j] = INF;
		}
	}
	
	printf("%d", BFS());
}
#endif