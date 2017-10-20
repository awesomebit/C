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
#define RED -1
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define ALIVE 100
#define DEAD -100
int WP;
int q[1000000];

void inputData(void)
{
	int i;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= K; i++)
	{
		//dir 상: 1, 하: 2, 좌: 3, 우: 4
		scanf("%d %d %d %d", &cell[i].i, &cell[i].j, &cell[i].cnt, &cell[i].dir);
		map[cell[i].i][cell[i].j] = 1;
		cell[i].life = ALIVE;
	}

	for (i = 0; i < N; i++)
	{
		map[0][i] = RED;
		map[i][0] = RED;
		map[N-1][i] = RED;
		map[i][N-1] = RED;
	}
}

void init(void)
{
	memset(cell, 0, sizeof(Q[1010]));
	memset(map, 0, sizeof(map));
	memset(q, 0, sizeof(q));
	WP = 0;
}

int move(int idx)
{
	// 한칸 이동
	int ni, nj;
	ni = cell[idx].i + di[cell[idx].dir];
	nj = cell[idx].j + dj[cell[idx].dir];
	map[cell[idx].i][cell[idx].j]--;
	map[ni][nj]++;

	// 약품을 밟으면 미생물 절반 죽고 이동방향 반대로 바뀜
	if (map[ni][nj] == RED)
	{
		cell[idx].cnt /= 2;
		if (cell[idx].cnt <= 0)
		{
			cell[idx].life = DEAD;
			map[ni][nj]--;
			return;
		}
		int tmpdir = cell[idx].dir;
		if (tmpdir == UP) cell[idx].dir = DOWN;
		else if (tmpdir == DOWN) cell[idx].dir = UP;
		else if (tmpdir == LEFT) cell[idx].dir = RIGHT;
		else if (tmpdir == RIGHT) cell[idx].dir = LEFT;
	}
	return;
}

void combine(void)
{
	// 미생물 군집 합쳐지는 것 구현해야 함


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
		sol += cell[i].cnt;
	}
	return sol;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		inputData();
		printf("%d", solve());

		init();
	}
	return 0;
}
#endif
