//////////////////////////////////////////////////////
//문제 번호 B: [TST]로봇 sol
//////////////////////////////////////////////////////
#if 01
#include <stdio.h>

int R, C;
int map[110][110];
int si, sj, sdir;
int ei, ej, edir;
int chk[4][110][110];
typedef struct st
{
	int i, j, dir, cnt;
}ROBOT;
ROBOT queue[110*110*4+10];
int wp, rp;
#define Enqueue(X) (queue[wp++] = (X))
#define Dequeue(X) ((X) = queue[rp++])
#define QueueNotEmpty (wp > rp)

void inputData(void)
{
	//dir을 원하는 방향으로 (시계방향) 바꾸기
	int lut[] = { 0, 1, 3, 2, 0 };
	int i, j;

	scanf("%d %d", &R, &C);
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d %d %d ", &si, &sj, &sdir);
	scanf("%d %d %d ", &ei, &ej, &edir);

	sdir = lut[sdir];
	edir = lut[edir];
	
	// map 벽만들기
	for (i = 1; i <= R; i++)
	{
		map[i][0] = 1;
		map[i][C + 1] = 1;
	}
	for (j = 1; j <= C; j++)
	{
		map[0][j] = 1;
		map[R + 1][j] = 1;
	}
}

int BFS(void)
{
	ROBOT data, ndata;
	int di[] = { -1, 0, 1, 0 };
	int dj[] = { 0, 1, 0, -1 };

	data.i = si;
	data.j = sj;
	data.dir = sdir;
	data.cnt = 0;
	Enqueue(data);
	chk[sdir][si][sj] = 1;

	while (QueueNotEmpty)
	{
		Dequeue(data);

		// Go 1, 2, 3
		ndata = data;
		ndata.cnt += 1;
		int k;
		for (k = 1; k <= 3; k++)
		{
			ndata.i += di[ndata.dir];
			ndata.j += dj[ndata.dir];

			if (map[ndata.i][ndata.j] == 1) break;
			if (chk[ndata.dir][ndata.i][ndata.j] == 1) continue;

			// 종료조건
			if (ndata.i == ei && ndata.j == ej && ndata.dir == edir) return ndata.cnt;
			//
			Enqueue(ndata);
			chk[ndata.dir][ndata.i][ndata.j] = 1;
		}

		// turn left
		ndata = data;
		ndata.cnt += 1;
		ndata.dir = (data.dir + 3) % 4;
		if (chk[ndata.dir][ndata.i][ndata.j] == 0)
		{
			// 종료조건
			if (ndata.i == ei && ndata.j == ej && ndata.dir == edir) return ndata.cnt;
			//
			Enqueue(ndata);
			chk[ndata.dir][ndata.i][ndata.j] = 1;
		}

		// turn right
		ndata.dir = (data.dir + 1) % 4;
		if (chk[ndata.dir][ndata.i][ndata.j] == 0)
		{
			// 종료조건
			if (ndata.i == ei && ndata.j == ej && ndata.dir == edir) return ndata.cnt;
			//
			Enqueue(ndata);
			chk[ndata.dir][ndata.i][ndata.j] = 1;
		}
	}

	// debugging
	return -1;
}

int main(void)
{
	inputData();
	printf("%d", BFS());

	return 0;
}
#endif
