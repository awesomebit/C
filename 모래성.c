///////////////////////////////////////////////
//문제 번호 C: [TST] 모래성
///////////////////////////////////////////////
#if 01
#include <stdio.h>

typedef struct st
{
	int i, j;
}CASTLE;

CASTLE q[1000 * 1000 + 10];

int H, W;
char map[1000 + 10][1000 + 10];
int chk[1000 + 10][1000 + 10];

int di[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dj[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int wp, rp;
int sol;

int wave(void)
{
	int flag = 0;
	int ti, tj;
	int ni, nj;
	int tmp = wp;

	// wp는 tmp 에 먼저 저장해서 새롭게 무너진 성의 좌표 ('.'으로 바뀐 부분) 전까지 rp로 체크한다
	while (tmp > rp)
	{
		ti = q[rp].i;
		tj = q[rp++].j;

		int k;
		for (k = 0; k < 8; k++)
		{
			ni = ti + di[k];
			nj = tj + dj[k];

			if (ni < 1 || ni > H || nj < 1 || nj > W) continue;
			if (chk[ni][nj] == 1) continue;

			// 어찌됐건 성보다 더 많은 수의 "파도좌표"가 8방면에 존재하면 성을 깎는다.
			if (map[ni][nj] != '.')	map[ni][nj]--;

			// map이 0이 되면 성이 무너진 상태이므로 큐에 새로운 "파도좌표"를 저장한다.
			if (map[ni][nj] == '0')
			{
				map[ni][nj] = '.';
				chk[ni][nj] = 1;
				q[wp].i = ni;
				q[wp++].j = nj;

				// 성이 한번이라도 무너지면 flag를 1로.
				flag = 1;
			}
		}
	}
	return flag;
}

void main(void)
{
	scanf("%d %d", &H, &W);
	int i, j;
	for (i = 1; i <= H; i++)
	{
		for (j = 1; j <= W; j++)
		{
			scanf(" %c", &map[i][j]);

			// 먼저 "파도좌표"를 큐에 저장한다.
			if (map[i][j] == '.')
			{
				q[wp].i = i;
				q[wp++].j = j;
				chk[i][j] = 1;
			}
		}
	}

	// 파도가 성을 무너뜨릴 수 있을 때까지 sol 증가
	while (wave()) sol++;
	printf("%d", sol);
}
#endif
