///////////////////////////////////////////////
//문제 번호 G: [TST] 트랙터
///////////////////////////////////////////////
#if 01
#include <stdio.h>

#define ABS(x) (((x) > 0) ? (x) : (-(x)))
int N;
int map[500 + 10][50 + 10];
int chk[500 + 10][50 + 10];
int ff_cnt;		// flood fill count

void INPUT_DATA(void)
{
	scanf("%d", &N);
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for (i = 0; i <= N + 1; i++)
	{
		chk[0][i] = 1;
		chk[N+1][i] = 1;
		chk[i][0] = 1;
		chk[i][N+1] = 1;
	}
}

void INIT_CHECK(void)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			chk[i][j] = 0;
		}
	}
}

void FLOODFILL(int i, int j, int pow)
{
	// static 으로 매번 생성하는 것 방지
	static int di[] = { 0, 0, 1, -1 };
	static int dj[] = { -1, 1, 0, 0 };
	int ni, nj;

	chk[i][j] = 1;
	ff_cnt++;

	int k;
	for (k = 0; k < 4; k++)
	{
		ni = i + di[k];
		nj = j + dj[k];

		if (chk[ni][nj] == 0 && ABS(map[i][j] - map[ni][nj]) <= pow)
		{
			FLOODFILL(ni, nj, pow);
		}
	}
}

int CHECK(int pow)
{
	int i, j;
	int threshold = (N * N) / 2 + (N % 2);	// 기준점
	INIT_CHECK();

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (chk[i][j] == 0)
			{
				ff_cnt = 0;
				FLOODFILL(i, j, pow);

				// ff_cnt가 기준점 이상에서 끝나면 성공
				if (threshold <= ff_cnt) return;
			}
		}
	}
	return 0;
}

int FIND(void)
{
	int start, end, mid, sol;
	start = 0; end = 0x7fffffff;

	// 이진탐색 
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (CHECK(mid))
		{
			sol = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}

	return sol;
}

void main(void)
{
	INPUT_DATA();
	printf("%d", FIND());
}
#endif
