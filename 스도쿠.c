///////////////////////////////////////////////
//문제 번호 F: [TST]스도쿠
///////////////////////////////////////////////
#if 01
#include <stdio.h>

typedef struct st
{
	int i, j;
}BIN;

BIN q[11 * 11 + 1];
int sudoku[11][11];
int N;
int win;

int check(int i, int j, int num)
{
	int k;
	for (k = 1; k <= 9; k++)
	{
		if (sudoku[i][k] == num) return 1;
		if (sudoku[k][j] == num) return 1;
	}
	return 0;
}

int _chks(int y, int x, int num)
{
	int i, j;
	for (i = y; i < y + 3; i++)
	{
		for (j = x; j < x + 3; j++)
		{
			if (sudoku[i][j] == num) return 1;
		}
	}
	return 0;
}

int chkSquare(int i, int j, int num)
{
	int squareNum = 0;
	int ret = 0;

	if (i >= 1 && i <= 3 && j >= 1 && j <= 3) squareNum = 1;
	else if (i >= 1 && i <= 3 && j >= 4 && j <= 6) squareNum = 2;
	else if (i >= 1 && i <= 3 && j >= 7 && j <= 9) squareNum = 3;

	else if (i >= 4 && i <= 6 && j >= 1 && j <= 3) squareNum = 4;
	else if (i >= 4 && i <= 6 && j >= 4 && j <= 6) squareNum = 5;
	else if (i >= 4 && i <= 6 && j >= 7 && j <= 9) squareNum = 6;

	else if (i >= 7 && i <= 9 && j >= 1 && j <= 3) squareNum = 7;
	else if (i >= 7 && i <= 9 && j >= 4 && j <= 6) squareNum = 8;
	else squareNum = 9;

	switch (squareNum)
	{
	case 1: ret = _chks(1, 1, num); break;
	case 2:	ret = _chks(1, 4, num); break;
	case 3: ret = _chks(1, 7, num); break;
	case 4: ret = _chks(4, 1, num); break;
	case 5: ret = _chks(4, 4, num); break;
	case 6: ret = _chks(4, 7, num); break;
	case 7: ret = _chks(7, 1, num); break;
	case 8: ret = _chks(7, 4, num); break;
	case 9: ret = _chks(7, 7, num); break;
	}

	return ret;
}

void print(void)
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			printf("%d ", sudoku[i][j]);
		}
		printf("\n");
	}
}

void DFS(int n, int i, int j)
{
	if (win == 1) return;
	
	if (n >= N)
	{
		// sudoku 배열에서 0이었던 부분 다시 0으로 리셋시키므로 여기까지 도달하면 프린트하기.
		print();
		win = 1;
		return;
	}

	int k;
	for (k = 1; k <= 9; k++)
	{	
		// 조건
		if (check(i, j, k) || chkSquare(i, j, k)) continue;
		sudoku[i][j] = k;
		DFS(n + 1, q[n + 1].i, q[n + 1].j);
		sudoku[i][j] = 0;
	}
}

void main(void)
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			scanf("%d ", &sudoku[i][j]);
			if (sudoku[i][j] == 0)
			{
				q[N].i = i;
				q[N++].j = j;
			}
		}
	}

	DFS(0, q[0].i, q[0].j);
}
#endif
