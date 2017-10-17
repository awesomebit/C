////////////////////////////////////////////
//연구소 
////////////////////////////////////////////
#if 01
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N, M;
int map[10][10];
typedef struct st
{
	int i, j;
}POSITION;
POSITION virus[10 * 10];
POSITION empty[10 * 10];
POSITION queue[10 * 10 * 10];
int e;
int v;
int wp, rp;
int fillchk[10][10];
int sol;

void inputData(void)
{
	int i, j;

	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
			{
				empty[e].i = i;
				empty[e++].j = j;
			}
			if (map[i][j] == 2)
			{
				virus[v].i = i;
				virus[v++].j = j;
			}
		}
	}
}

int spreadVirus(void)
{
	// chkfill 배열 초기화, wp, rp 초기화
	memset(fillchk, 0, sizeof(int[10][10]));
	wp = 0; rp = 0;
	static int di[] = { -1, 0, 1, 0 };
	static int dj[] = { 0, 1, 0, -1 };
	POSITION data, ndata;
	int i;

	// initial enqueue
	for (i = 0; i < v; i++)
	{
		ndata.i = virus[i].i;
		ndata.j = virus[i].j;
		queue[wp++] = ndata;
		fillchk[ndata.i][ndata.j] = 1;
	}

	// dequeue
	while (wp > rp)
	{
		data = queue[rp++];
		ndata = data;

		int k;
		for (k = 0; k < 4; k++)
		{
			ndata.i = data.i + di[k];
			ndata.j = data.j + dj[k];

			if (ndata.i < 1 || ndata.i > N || ndata.j < 1 || ndata.j > M) continue;
			if (map[ndata.i][ndata.j] != 0 || fillchk[ndata.i][ndata.j] != 0) continue;

			fillchk[ndata.i][ndata.j] = 1;
			// enqueue
			queue[wp++] = ndata;
		}
	}
}

int safeZone(void)
{
	int ret = 0;
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			if (map[i][j] == 0 && fillchk[i][j] == 0) ret++;
		}
	}
	return ret;
}

void solve(void)
{
	int i, j, k;
	// MAX 안전영역의 크기 (0의 갯수)를 구해보자
	// 1) 벽을 설치하고 (3개) for문 3개
	// 2) 바이러스를 퍼뜨려본다 BFS

	// 벽 쌓기
	for (k = 0; k < e - 2; k++)
	{
		map[empty[k].i][empty[k].j] = 1;
		for (i = k + 1; i < e - 1; i++)
		{
			map[empty[i].i][empty[i].j] = 1;
			for (j = i + 1; j < e; j++)
			{
				map[empty[j].i][empty[j].j] = 1;
				
				// BFS로 바이러스 퍼뜨려보자
				spreadVirus();

				// 안전영역 체크해보자
				int tmp = safeZone();
				if (sol < tmp) sol = tmp;

				map[empty[j].i][empty[j].j] = 0;
			}
			map[empty[i].i][empty[i].j] = 0;
		}
		map[empty[k].i][empty[k].j] = 0;
	}
}

int main(void)
{
	inputData();
	solve();
	printf("%d", sol);

	return 0;
}
#endif
