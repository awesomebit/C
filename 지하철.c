///////////////////////////////////////////
//���� ��ȣ T: [TST]����ö
///////////////////////////////////////////
#if 0
#include <stdio.h>
#define INF 0x7fffffff;

int N;	//����ö �� ��
int M;	//�������� ��ȣ
int a[100 + 10][100 + 10];
int cost[100 + 10];
int chk[100 + 10];
int route[100 + 10];
int route2[100 + 10];
int sel;
int sol = 0;

void function(void)
{
	int k, i;

	for (k = 0; k < N - 1; k++)
	{
		// �ش� sel���� �� �� �ִ� ��ε��� cost���� �����ϰ�,
		for (i = 1; i <= N; i++)
		{
			if (chk[i] || a[sel][i] == 0) continue;
			if (cost[i] > (cost[sel] + a[sel][i]))
			{
				cost[i] = (cost[sel] + a[sel][i]);
				route[i] = sel;
			}
		}

		// �� cost ���� ���ؼ� �� ��η� �Ű��ش�.
		int min = INF;
		for (i = 1; i <= N; i++)
		{
			if (chk[i]) continue;
			if (min > cost[i])
			{
				min = cost[i];
				sel = i;
			}
		}
		chk[sel] = 1;
	}
}

void main(void)
{
	scanf("%d %d", &N, &M);
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &a[i][j]);
		}
		cost[i] = INF;
	}

	sel = 1;
	chk[1] = 1;
	cost[1] = 0;
	function();

	printf("%d\n", cost[M]);

	int temp = N;
	int n = 0;
	while(1)
	{
		route2[n++] = temp;
		temp = route[temp];
		if (temp == 0) break;
	}
	for (i = n-1; i >= 0; i--)
	{
		printf("%d ", route2[i]);
	}
}
#endif