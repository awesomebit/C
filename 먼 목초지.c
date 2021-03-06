///////////////////////////////////////
//문제 번호 A: [TEST] 먼 목초지
///////////////////////////////////////
#if 01
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
long long int A, B;
char map[40][40];
long long int sel[40][40];
#define INF 0x7ffffff
typedef struct
{
	int i, j;
}FARM;
FARM Q[100000];
int WP, RP;
int sol;
int n = 1;

void inputData(void)
{
	FARM data;

	scanf("%d %lld %lld", &N, &A, &B);
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf(" %c", &map[i][j]);
			sel[i][j] = INF;
			//init enqueue
			data.i = i;
			data.j = j;
			Q[n++] = data;
			WP = n;
		}
	}
}

void init(void)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			map[i][j] = 0;
			sel[i][j] = INF;
		}
	}
	memset(Q, 0, sizeof(FARM[1600]));
	WP = 0; RP = 0;
	sol = 0;
}

void BFS(void)
{
	// 도착지점까지 가장 적은 time(cost) 구하기
	static int di[] = { -1, 0, 1, 0 };
	static int dj[] = { 0, 1, 0, -1 };
	int ni, nj;
	FARM data, ndata;

	while (WP > RP)
	{
		// dequeue
		data = Q[RP++];
		ndata = data;

		int k;
		for (k = 0; k < 4; k++)
		{
			ndata.i = data.i + di[k];
			ndata.j = data.j + dj[k];

			if (ndata.i < 1 || ndata.i > N || ndata.j < 1 || ndata.j > N) continue;

			// 다음 방향으로 갈 때 필요한 time(cost) 계산
			int tcost;
			if (map[ndata.i][ndata.j] != map[data.i][data.j]) tcost = B;
			else if (map[ndata.i][ndata.j] == map[data.i][data.j]) tcost = A;

			// sel table에 정리
			if (sel[ndata.i][ndata.j] > sel[data.i][data.j] + tcost)
			{
				sel[ndata.i][ndata.j] = sel[data.i][data.j] + tcost;

				//enqueue
				Q[WP++] = ndata;
			}
		}
	}
}

int findMax(void)
{
	int i, j;
	int max = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (max < sel[i][j]) max = sel[i][j];
		}
	}

	return max;
}

int solve(void)
{
	int i, j;
	int k, l;
	int sol = 0;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j < N; j++)
		{
			WP = n;
			RP = 0;
			Q[0].i = i;
			Q[0].j = j;
			sel[i][j] = 0;
			BFS();

			int tmp;
			tmp = findMax();
			if (sol < tmp) sol = tmp;

			for (k = 1; k <= N; k++)
			{
				for (l = 1; l <= N; l++)
				{
					sel[k][l] = INF;
				}
			}
		}
	}

	return sol;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		inputData();
		printf("%d\n", solve());

		init();
	}

	return 0;
}

#endif
