//////////////////////////////////////////////////////
//문제 번호 A: [TST]월드컵
//////////////////////////////////////////////////////
#if 0
#include <stdio.h>

int table[6][3];
int flag = 0;

int lut[16][2] = 
{
	{0,0}, // 0
	{ 0, 1 }, // 1
	{ 0, 2 }, // 2
	{ 0, 3 }, // 3
	{ 0, 4 }, // 4
	{ 0, 5 }, // 5
	{ 1, 2 }, // 6
	{ 1, 3 }, // 7
	{ 1, 4 }, // 8
	{ 1, 5 }, // 9
	{ 2, 3 }, // 10
	{ 2, 4 }, // 11
	{ 2, 5 }, // 12
	{ 3, 4 }, // 13
	{ 3, 5 }, // 14
	{ 4, 5 } // 15
};

int DFS(int n)
{
	int i,t1,t2;

	t1 = lut[n][0];
	t2 = lut[n][1];

	if (n > 15)
	{
		return 1;
	}

	for (i = 0; i < 3;i++)
	{
		if (table[t1][i] && table[t2][2-i])
		{
			table[t1][i]--;
			table[t2][2 - i]--;
			if(DFS(n + 1)==1) return 1;
			table[t1][i]++;
			table[t2][2 - i]++;
		}
	}
	return 0;
}

int Input_Data(void)
{
	int i, j;
	int flag = 1;
	for (i = 0; i < 6;i++)
	{
		for (j = 0; j < 3;j++)
		{
			scanf("%d", &table[i][j]);
		}
		if (table[i][0] + table[i][1] + table[i][2] != 5)
		{
			flag = 0;
		}
	}
	return flag;
}

int main(void)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (Input_Data())
		{
			printf("%d ", DFS(1));
		}
		else printf("0 ");
	}
}
#endif
