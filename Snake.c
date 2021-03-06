////////////////////////////////////////////////
//문제 번호 : [TST] Snake
////////////////////////////////////////////////
#if 01
#include <stdio.h>

#define left90 10 
#define right90 20 

#define up 0
#define down 1 
#define left 2
#define right 3

typedef struct st
{
	int i, j;
}SET;
SET F[100 + 10];

int a[100*10000 + 10];
int map[100 + 10][100 + 10];

int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };

int N, K;
int r, c;
int L;

int snake = 1;
int cnt = 0;
int ni = 0;
int nj = 0;

void function(int n, int i, int j, int d)
{
	int dir = d;

	int l, k, m;
	for (l = 1; l <= K; l++)
	{
		if (i == F[l].i && j == F[l].j)
		{
			F[l].i = 0;
			F[l].j = 0;
			cnt++;
		}
	}

	for (l = 1; l <= N; l++)
	{
		for (k = 1; k <= N; k++)
		{
			for (m = n - cnt - 1; m < n - cnt; m++)
			{
				if (map[l][k] == m)
				{
					map[l][k] = 0;
				}
			}
		}
	}

	// 90도 꺾기
	if (a[n] == left90)
	{
		if (d == up)
		{
			dir = left;
		}
		else if (d == down)
		{
			dir = right;
		}
		else if (d == left)
		{
			dir = down;
		}
		else if (d == right)
		{
			dir = up;
		}
	}
	else if (a[n] == right90)
	{
		if (d == up)
		{
			dir = right;
		}
		else if (d == down)
		{
			dir = left;
		}
		else if (d == left)
		{
			dir = up;
		}
		else if (d == right)
		{
			dir = down;
		}
	}

	ni = i + di[dir];
	nj = j + dj[dir];
	
	// 벽에 부딪히면 종료
	if (ni < 1 || nj < 1) return;
	if (ni > N || nj > N) return;
	if (map[ni][nj] != 0) return;
	map[ni][nj] = snake++;

	function(n + 1, ni, nj, dir);
}

void main(void)
{
	scanf("%d %d", &N, &K);
	int k;
	for (k = 1; k <= K; k++)
	{
		scanf("%d %d", &F[k].i, &F[k].j);
	}
	scanf("%d", &L);

	int sec;
	char dir;
	int l;
	int set = 1

	for (k = 1; k <= L; k++)
	{
		scanf("%d", &sec);
		for (l = set; l <= sec; l++)
		{
			a[l] = 1;
		}
		set = sec + 1;
		scanf(" %c", &dir);
		if (dir == 'L')
		{
			a[set] = left90;
			set++;
		}
		else if (dir == 'D')
		{
			a[set] = right90;
			set++;
		}
	}

	map[1][1] = snake++;
	function(1, 1, 1, right);

	printf("%d", snake-1);
}
#endif

