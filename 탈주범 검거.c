//////////////////////////////////////////////
//1953. [모의 SW 역량테스트] 탈주범 검거
//////////////////////////////////////////////
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M;
int Y, X;
int L;
int map[60][60];
int visited[60][60];
typedef struct
{
	int i, j;
	int d;
}RUN;
RUN Q[50 * 50 * 50];
int WP, RP;
// 터널번호, 방향, 입출
int lut_tunnel[8][4][2] = { { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },\
{ { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 } }, \
{ { 1, 1 }, { 0, 0 }, { 1, 1 }, { 0, 0 } }, \
{ { 0, 0 }, { 1, 1 }, { 0, 0 }, { 1, 1 } }, \

{ { 0, 1 }, { 0, 1 }, { 1, 0 }, { 1, 0 } }, \
{ { 1, 0 }, { 0, 1 }, { 0, 1 }, { 1, 0 } }, \
{ { 1, 0 }, { 1, 0 }, { 0, 1 }, { 0, 1 } }, \
{ { 0, 1 }, { 1, 0 }, { 1, 0 }, { 0, 1 } } };

void inputData(void)
{
	int i, j;
	scanf("%d %d %d %d %d", &N, &M, &Y, &X, &L);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
}

void BFS(void)
{
	int visit = 1;
	static int di[] = { -1, 0, 1, 0 };
	static int dj[] = { 0, 1, 0, -1 };
	RUN data, ndata;

	// init enqueue
	ndata.i = Y;
	ndata.j = X;
	ndata.d = 1;
	Q[WP++] = ndata;
	visited[ndata.i][ndata.j] = ndata.d;

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
			ndata.d = data.d + 1;

			if (ndata.i < 0 || ndata.i > N - 1 || ndata.j < 0 || ndata.j > M - 1) continue;
			if (map[ndata.i][ndata.j] == 0) continue;
			if (visited[ndata.i][ndata.j] != 0) continue;

			// 갈 수 있는 길
			if (lut_tunnel[map[data.i][data.j]][k][1] == 1 
				&& lut_tunnel[map[ndata.i][ndata.j]][k][0] == 1)
			{
				// enqueue
				Q[WP++] = ndata;
				visited[ndata.i][ndata.j] = ndata.d;
			}

		}
	}
}

int solve(void)
{
	int i, j;
	int count = 0;

	BFS();

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (visited[i][j] > 0 && visited[i][j] <= L) count++;
		}
	}

	return count;
}

void init(void)
{
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(map));
	memset(Q, 0, sizeof(RUN[50*50*50]));
	WP = 0; RP = 0;
}

int main(void)
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
