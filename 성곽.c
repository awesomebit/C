////////////////////////////////////////////////
//문제 번호 : [TST] 성곽
////////////////////////////////////////////////
#if 01
#include <stdio.h>

#define up 0
#define down 1
#define left 2
#define right 3

int N, M;
int a[50 + 10][50 + 10];
int chk[50 + 10][50 + 10];
int chk2[50 + 10][50 + 10];
int chknum = 1;
int area[50*50 + 10];

void print(void)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			printf("%d ", chk[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int recursive(int n, int i, int j)
{
	int ni, nj;
	int t[4] = { 0, 0, 0, 0 };
	int temp = a[i][j];

	if (temp / 8 >= 1)
	{
		t[3] = 1;
		temp -= 8;
	}
	if (temp / 4 >= 1)
	{
		t[2] = 1;
		temp -= 4;
	}
	if (temp / 2 >= 1)
	{
		t[1] = 1;
		temp -= 2;
	}
	if (temp / 1 >= 1)
	{
		t[0] = 1;
		temp -= 1;
	}

	int di[] = { -1, 1, 0, 0 };
	int dj[] = { 0, 0, -1, 1 };

	int k;

	for (k = 0; k < 4; k++)
	{
		ni = i + di[k];
		nj = j + dj[k];

		// 사방면 벽인지 체크
		if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
		if (chk[ni][nj] != 0) continue;
		if (t[3] == 1 && k == down) continue;
		if (t[2] == 1 && k == right) continue;
		if (t[1] == 1 && k == up) continue;
		if (t[0] == 1 && k == left) continue;
	
		chk[ni][nj] = n;
		recursive(n, ni, nj);
	}
}

int recursive2(int i, int j)
{
	int sol = 0;
	int ni, nj;
	
	int di[] = { -1, 1, 0, 0 };
	int dj[] = { 0, 0, -1, 1 };

	int k;
	for (k = 0; k < 4; k++)
	{
		ni = i + di[k];
		nj = j + dj[k];

		if (ni < 1 || ni > N || nj < 1 || nj > M) continue;

		if (chk[ni][nj] != chk[i][j])
		{
			sol = area[chk[ni][nj]] + area[chk[i][j]];
		}
	}
	return sol;
}

void main(void)
{
	scanf("%d %d", &N, &M);
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	// 방의 개수 구하기
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			if (chk[i][j] == 0)
			{
				chk[i][j] = chknum;
				int set = recursive(chknum++, i, j);
				//print();
			}
		}
	}

	// 가장 큰 방의 크기 구하기
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			area[chk[i][j]]++;
		}
	}
	int max1 = 0;
	for (i = 1; area[i] != 0; i++)
	{
		if (max1 < area[i])
		{
			max1 = area[i];
		}
	}

	int max2 = 0;
	// 하나의 벽 제거해서 가장 큰 방 크기 구하기
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			int tmp = recursive2(i, j);
			if (max2 < tmp)
			{
				max2 = tmp;
			}
		}
	}

	printf("%d\n", chknum-1);
	printf("%d\n", max1);
	printf("%d\n", max2);
}
#endif