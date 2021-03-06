////////////////////////////////////////////////
//문제 번호 G: [TST] 트랙터
////////////////////////////////////////////////
#if 01
#include <stdio.h>

#define ABS(x) ((x)>0?(x):-(x))
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)>(y)?(y):(x))
#define QUE 100000
#define INF 0x7fffffff
typedef struct st
{
	int i, j;
}COORD;
COORD q[500 * 500 + 10];
int N;
int map[500 + 10][500 + 10];
int chk[500 + 10][500 + 10];
int set;
int flag = 1;
int min = INF;
int max;
int start, end;
int mid;
int sol = INF;
int wp, rp;

int BFS(int i, int j, int pow)
{
	int di[] = { -1, 0, 1, 0 };
	int dj[] = { 0, 1, 0, -1 };
	int ni, nj;
	int ti, tj;
	int count = 1;  // 돌아다닌 들판 수

	// initial enque
	q[wp].i = i;
	q[wp++].j = j;
	wp %= QUE;
	chk[i][j] = flag;

	// deque
	for (;;)
	{
		if (rp == wp) break;

		ti = q[rp].i;
		tj = q[rp++].j;
		rp %= QUE;

		int k;
		for (k = 0; k < 4; k++)
		{
			ni = ti + di[k];
			nj = tj + dj[k];

			// 검색 범위 조건
			if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
			if (chk[ni][nj] == flag) continue;

			// 트랙터 성능 조건
			if (ABS(map[ti][tj] - map[ni][nj]) > pow) continue;

			// 조건 통과하면 enque
			q[wp].i = ni;
			q[wp++].j = nj;
			wp %= QUE;
			chk[ni][nj] = flag;
			count++;
		}
	}
	return count;
}

void main(void)
{
	scanf("%d", &N);
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			max = MAX(max, map[i][j]);
			min = MIN(min, map[i][j]);
		}
	}
	set = N % 2 ? ((N*N) / 2 + 1) : ((N*N) / 2);

	// binary search
	start = min; 
	end = max;
	while (start <= end)
	{
		mid = (start + end) / 2;
		// s가 트랙터의 성능. 증가 성능으로 처음 과반수 이상 들판을 돌아다니면 break.
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (chk[i][j] == flag) continue;
				if (BFS(i, j, mid) >= set)
				{
					end = mid - 1;
					sol = MIN(sol, mid);
					goto back;
				}
				
			}
		}
		start = mid + 1;
	back:
		flag++;
	}
	printf("%d", sol);
}
#endif
