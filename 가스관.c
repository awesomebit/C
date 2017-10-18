///////////////////////////////////////////
//문제 번호 A: [TEST] 가스관
///////////////////////////////////////////
#if 01
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int R, C;
int map[150][150];
char origin[150][150];
// visited, 북, 동, 남, 서
int chk[150][150][5];
int si, sj;
int ei, ej;
#define START 10
#define END 20
#define OPEN 1
#define EMPTY 2
// visited, 북, 동, 남, 서
int di[5] = { 0, -1, 0, 1, 0 };
int dj[5] = { 0, 0, 1, 0, -1 };
typedef struct
{
	int i, j;
	int dir;
	int p;	// 0 은 시작점부터, 1은 종료점부터 끝긴 지점.
}ENDPOINT;
ENDPOINT Q[150 * 150];
int q;
int soli, solj;
char solch;
int lut[7][5] = { { 0, 1, 0, 1, 0 }, { 0, 0, 1, 0, 1 }, { 0, 1, 1, 1, 1 }, \
			{ 0, 0, 1, 1, 0 }, { 0, 1, 1, 0, 0 }, { 0, 1, 0, 0, 1 }, { 0, 0, 0, 1, 1 } };
char lutidx[7] = { '|', '-', '+', '1', '2', '3', '4' };

void inputData(void)
{
	int i, j;
	char ch;
	int tmpi, tmpj;
	scanf("%d %d", &R, &C);
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			scanf(" %c", &ch);
			origin[i][j] = ch;
			if (ch == 'Z')
			{
				ei = i;
				ej = j;
				chk[i][j][0] = 0;
				map[i][j] = END;
			}
			else if (ch == 'M')
			{
				si = i;
				sj = j;
				chk[i][j][0] = 0;
				map[i][j] = START;
			}
			else if (ch == '|')
			{
				chk[i][j][0] = 0;
				chk[i][j][1] = 0;
				chk[i][j][2] = 1;
				chk[i][j][3] = 0;
				chk[i][j][4] = 1;
				map[i][j] = OPEN;
			}
			else if (ch == '-')
			{
				chk[i][j][0] = 0;
				chk[i][j][1] = 1;
				chk[i][j][2] = 0;
				chk[i][j][3] = 1;
				chk[i][j][4] = 0;
				map[i][j] = OPEN;
			}
			else if (ch == '+')
			{
				chk[i][j][0] = 0;
				chk[i][j][1] = 0;
				chk[i][j][2] = 0;
				chk[i][j][3] = 0;
				chk[i][j][4] = 0;
				map[i][j] = OPEN;
			}
			else if (ch == '1')
			{
				chk[i][j][0] = 0;
				chk[i][j][1] = 1;
				chk[i][j][2] = 0;
				chk[i][j][3] = 0;
				chk[i][j][4] = 1;
				map[i][j] = OPEN;
			}
			else if (ch == '2')
			{
				chk[i][j][0] = 0;
				chk[i][j][1] = 0;
				chk[i][j][2] = 0;
				chk[i][j][3] = 1;
				chk[i][j][4] = 1;
				map[i][j] = OPEN;
			}
			else if (ch == '3')
			{
				chk[i][j][0] = 0;
				chk[i][j][1] = 0;
				chk[i][j][2] = 1;
				chk[i][j][3] = 1;
				chk[i][j][4] = 0;
				map[i][j] = OPEN;
			}
			else if (ch == '4')
			{
				chk[i][j][0] = 0;
				chk[i][j][1] = 1;
				chk[i][j][2] = 1;
				chk[i][j][3] = 0;
				chk[i][j][4] = 0;
				map[i][j] = OPEN;
			}
			else
			{
				map[i][j] = EMPTY;
			}
		}
	}
}

int floodfill(int y, int x, int p)
{
	int ni, nj;
	int k;
	int flag = 1;

	chk[y][x][0] = 1;

	for (k = 1; k <= 4; k++)
	{
		ni = y + di[k];
		nj = x + dj[k];

		if (ni < 0 || ni > R + 1 || nj < 0 || nj > C + 1) continue;
		if (chk[y][x][k] == 1) continue;	// 가스관이 막혀있는 쪽은 못 감
		if (chk[ni][nj][0] == 1) continue;	// 이미 visit한 곳은 못 감

		// map에서 뚫려있지 않은 곳은 못 감
		if (map[ni][nj] == OPEN )
		{
			floodfill(ni, nj, p);
			flag = 0;
		}
		else if (map[ni][nj] == EMPTY)
		{
			if ((y == si && x == sj) || (y == ei && x == ej)) continue;
			// 끊긴 좌표와 방향 저장
			Q[q].i = ni;
			Q[q].j = nj;
			int tmpdir;
			if (k == 1) tmpdir = 3;
			else if (k == 2) tmpdir = 4;
			else if (k == 3) tmpdir = 1;
			else if (k == 4) tmpdir = 2;
			Q[q].dir = tmpdir;
			Q[q++].p = p;
		}
	}
}

int function(void)
{
	//시작점에서부터 끊긴 곳까지
	floodfill(si, sj, 0);

	//종료점에서부터 끊긴 곳까지
	floodfill(ei, ej, 1);

	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			// 시작점, 종료점부터 floodfill로 돌아보지 않은 곳 체크
			if (origin[i][j] != '.' && chk[i][j][0] == 0)
			{
				floodfill(i, j, 2);
				return;
			}
		}
	}
}

int solve(void)
{
	// 정답 좌표 계산
	int i,j;
	int tmp[5] = { 0 };
	for (i = 0; Q[i].dir != 0; i++)
	{
		tmp[Q[i].dir] = 1;
		for (j = 0; j < i; j++)
		{
			if ((Q[i].i == Q[j].i) && (Q[i].j == Q[j].j))
			{
				soli = Q[i].i;
				solj = Q[i].j;
			}
		}
	}

	int cnt = 0;
	// 정답 가스관 계산
	for (i = 0; i < 7; i++)
	{
		cnt = 0;
		for (j = 1; j <= 4; j++)
		{
			if (tmp[j] == lut[i][j]) cnt++;
		}
		if (cnt == 4)
		{
			solch = lutidx[i];
			return 1;
		}
	}
	
	return 0;

}

void printCheckArray(void)
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			printf("%d ", chk[i][j][0]);
		}
		printf("\n");
	}
	printf("\n");
}

void init(void)
{
	// 초기화
	memset(map, 0, sizeof(int[150][150]));
	memset(chk, 0, sizeof(int[150][150][5]));
	si = 0; sj = 0; ei = 0; ej = 0;

	// 구조체 memset 초기화?
	memset(Q, 0, sizeof(ENDPOINT[150*150]));
	q = 0;
	soli = 0; solj = 0; solch = 0;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		inputData();
		function();
		//printCheckArray();
		solve();
		printf("%d %d %c\n", soli + 1, solj + 1, solch);

		init();
	}

	return 0;
}
#endif
