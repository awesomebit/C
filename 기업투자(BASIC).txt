///////////////////////////////////////////
//문제 번호 R: [TST]기업투자(BASIC)
///////////////////////////////////////////
#if 0
#include <stdio.h>

int investment;
int company;

int I[30 + 10];
int C[30 + 10][7 + 10];
int chk_investment[30 + 10];
int chk_company[7 + 10];
int s[7 + 10];
int ps[7 + 10];
int max = 0;

int Check(int k)
{
	int i;
	int sum = 0;
	for (i = 1; i <= investment; i++)
	{
		if (chk_investment[i]) sum += i * chk_investment[i];
	}
	sum += k;

	// 투자 가능한 액수 초과할 경우 1 리턴.
	if (sum > investment) return 1;
	else return 0;
}

int DFS(int n, int sum, int inv)
{
	if (n > company)
	{
		if (sum > max)
		{
			int i;
			for (i = 1; i <= company; i++)
			{
				ps[i] = s[i];
			}
			max = sum;
		}
	
		return;
	}
	
	int k;
	for (k = 0; k <= investment; k++)
	{
		if (chk_company[n] == 1 || Check(k)) continue;

		chk_company[n] = 1;
		chk_investment[k]++;
		//printf("%d\n", C[k][n]);
		s[n] = k;
		DFS(n + 1, sum + C[k][n], k);
		chk_investment[k]--;
		chk_company[n] = 0;
	}
}

void main(void)
{
	scanf("%d %d", &investment, &company);
	int i, j;
	for (i = 1; i <= investment; i++)
	{
		scanf("%d", &I[i]);
		for (j = 1; j <= company; j++)
		{
			scanf("%d", &C[i][j]);
		}
	}

	DFS(1, 0, investment);
	
	printf("%d\n", max);

	for (i = 1; i <= company; i++)
	{
		printf("%d ", ps[i]);
	}

}
#endif