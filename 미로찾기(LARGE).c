//////////////////////////////////////////
//문제 번호 H: [TST]미로찾기(LARGE)
//////////////////////////////////////////
#if 01
#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
	int i, j;
	int d;
}MIRO;
MIRO Q[4002 * 4002];
int H, W;
char map[4002][4002];
int chk[4002][4002];
int si, sj;
int ei, ej;
int wp, rp;
#define QUE 100000
#define INF 0x7fffffff
int sol = INF;

void inputData(void)
{
	scanf("%d %d", &H, &W);
	int i, j;
	for (i = 1; i <= H; i++)
	{
		for (j = 1; j <= W; j++)
		{
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S')
			{
				si = i;
				sj = j;
			}
			if (map[i][j] == 'G')
			{
				ei = i;
				ej = j;
			}
		}
	}
}

void BFS(void)
{
	MIRO data, ndata;
	int di[] = { -1, 0, 1, 0 };
	int dj[] = { 0, 1, 0, -1 };

	// init enqueue
	data.i = si;
	data.j = sj;
	data.d = 0;
	Q[wp++] = data;
	chk[si][sj] = 1;
	wp %= QUE;

	for (;;)
	{
		// dequeue
		data = Q[rp++];
		rp %= QUE;

		if (wp == rp) return;

		int k;
		for (k = 0; k < 4; k++)
		{
			ndata.i = data.i + di[k];
			ndata.j = data.j + dj[k];
			ndata.d = data.d + 1;

			if (ndata.i < 1 || ndata.i > H || ndata.j < 1 || ndata.j > W)
			if (map[ndata.i][ndata.j] == '#') continue;
			if (chk[ndata.i][ndata.j] == 1) continue;

			if (ndata.i == ei && ndata.j == ej)
			{
				if (sol > ndata.d) sol = ndata.d;
			}

			Q[wp++] = ndata;
			chk[ndata.i][ndata.j] = 1;
			wp %= QUE;
		}
	}
}


int main(void)
{
	inputData();
	BFS();
	printf("%d", sol);

	return 0;
}
#endif
