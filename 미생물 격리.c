////////////////////////////////////////////
//2382. [모의 SW 역량테스트] 미생물 격리
////////////////////////////////////////////
#if 01
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//셀의 개수 N, 격리 시간 M, 미생물 군집의 개수 K
int N, M, K;
typedef struct
{
	int i, j;
	int cnt;
	int dir;
	int life;
}CELL;
CELL cell[1010];
//dir 상: 1, 하: 2, 좌: 3, 우: 4
int di[] = { 0, -1, 1, 0, 0 };
int dj[] = { 0, 0, 0, -1, 1 };
int map[110][110];
int chk[110][110];
#define RED -1
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define ALIVE 100
#define DEAD -100

void inputData(void)
{
	int i;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= K; i++)
	{
		//dir 상: 1, 하: 2, 좌: 3, 우: 4
		scanf("%d %d %d %d", &cell[i].i, &cell[i].j, &cell[i].cnt, &cell[i].dir);
		chk[cell[i].i][cell[i].j] = 1;
		cell[i].life = ALIVE;
	}

	for (i = 0; i < N; i++)
	{
		map[0][i] = RED;
		map[i][0] = RED;
		map[N - 1][i] = RED;
		map[i][N - 1] = RED;
	}
}

void init(void)
{
	memset(cell, 0, sizeof(CELL[1010]));
	memset(map, 0, sizeof(map));
	memset(map, 0, sizeof(chk));
}

int move(int idx)
{
	// 한칸 이동
	int ni, nj;
	ni = cell[idx].i + di[cell[idx].dir];
	nj = cell[idx].j + dj[cell[idx].dir];
	chk[cell[idx].i][cell[idx].j]--;
	chk[ni][nj]++;
	cell[idx].i = ni;
	cell[idx].j = nj;

	// 약품을 밟으면 미생물 절반 죽고 이동방향이 반대로 바뀜
	if (map[ni][nj] == RED)
	{
		cell[idx].cnt /= 2;
		if (cell[idx].cnt <= 0)
		{
			cell[idx].life = DEAD;
			chk[ni][nj]--;
			return 0;
		}
		int tmpdir = cell[idx].dir;
		if (tmpdir == UP) cell[idx].dir = DOWN;
		else if (tmpdir == DOWN) cell[idx].dir = UP;
		else if (tmpdir == LEFT) cell[idx].dir = RIGHT;
		else if (tmpdir == RIGHT) cell[idx].dir = LEFT;
	}
	return 1;
}

void combine(void)
{
	// 미생물 군집 합쳐지는 것 구현해야 함
	int i, j, k;
	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= N; j++)
		{
			if (chk[i][j] > 1)
			{
				int maxidx = 0;
				int cntmax = 0;
				int cntsum = 0;
				for (k = 1; k <= K; k++)
				{	
					if (cell[k].life == DEAD) continue;
					if (cell[k].i == i && cell[k].j == j)
					{
						if (chk[i][j] > 1) chk[i][j]--;
						cntsum += cell[k].cnt;
						if (cntmax < cell[k].cnt)
						{
							cell[maxidx].life = DEAD;
							cntmax = cell[k].cnt;
							maxidx = k;
						}
						else cell[k].life = DEAD;
					}
				}
				cell[maxidx].cnt = cntsum;
				////////
			}
		}
	}
}

int solve(void)
{
	int sol = 0;
	int i;

	while (M--)
	{
		for (i = 1; i <= K; i++)
		{
			if (cell[i].life == DEAD) continue;
			move(i);
		}
		combine();

	}

	// 미생물 세기
	for (i = 1; i <= K; i++)
	{
		if (cell[i].life == DEAD) continue;
		sol += cell[i].cnt;
	}
	return sol;
}

int main()
{
	int num = 1;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		inputData();
		printf("#%d %d\n", num++, solve());

		init();
	}
	return 0;
}
#endif
