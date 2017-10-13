///////////////////////////////////////////////
//문제 번호 B: [TST]색종이 만들기
///////////////////////////////////////////////
#if 0
#include <stdio.h>

int N;
int map[128 + 10][128 + 10];
int chk[128 + 10][128 + 10];
int white;
int blue;

void checkArray(int y, int x, int dist)
{
	int i, j;
	for (i = y; i < y + dist; i++)
	{
		for (j = x; j < x + dist; j++)
		{
			chk[i][j] = 1;
		}
	}
}

void search(int y, int x, int dist)
{
	int cnt0 = 0;
	int cnt1 = 0;
	int i, j;
	for (i = y; i < y + dist; i++)
	{
		for (j = x; j < x + dist; j++)
		{
			if (chk[i][j]) continue;
			if (map[i][j] == 0) cnt0++;
			if (map[i][j] == 1) cnt1++;
		}
	}

	if (cnt0 == dist * dist)
	{
		white++;
		checkArray(y, x, dist);
	}
	else if (cnt1 == dist * dist)
	{
		blue++;
		checkArray(y, x, dist);
	}
}

void function(void)
{
	int i, j;
	switch (N)
	{
	case 128:
	{
		for (i = 1; i <= N; i+=128)
		{
			for (j = 1; j <= N; j+=128)
			{
				search(i, j, 128);
			}
		}
	}
	case 64:
	{
		for (i = 1; i <= N; i+=64)
		{
			for (j = 1; j <= N; j+=64)
			{
				search(i, j, 64);
			}
		}
	}
	case 32: 
	{
		for (i = 1; i <= N; i += 32)
		{
			for (j = 1; j <= N; j += 32)
			{
				search(i, j, 32);
			}
		}
	}
	case 16: 
	{
		for (i = 1; i <= N; i += 16)
		{
			for (j = 1; j <= N; j += 16)
			{
				search(i, j, 16);
			}
		}
	}
	case 8: 
	{
		for (i = 1; i <= N; i += 8)
		{
			for (j = 1; j <= N; j += 8)
			{
				search(i, j, 8);
			}
		}
	}
	case 4: 
	{
		for (i = 1; i <= N; i += 4)
		{
			for (j = 1; j <= N; j += 4)
			{
				search(i, j, 4);
			}
		}
	}
	case 2: 
	{
		for (i = 1; i <= N; i += 2)
		{
			for (j = 1; j <= N; j += 2)
			{
				search(i, j, 2);
			}
		}
	}
	default: 
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				search(i, j, 1);
			}
		}
	}
	return;
	}
}

int main(void)
{
	scanf("%d", &N);
	//하얀색 0, 파란색 1
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	function();
	printf("%d\n%d", white, blue);
}
#endif
