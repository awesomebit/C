////////////////////////////////////////////////
//문제 번호 : [TST]좋은 수열
////////////////////////////////////////////////
#if 0
#include <stdio.h>

#define INF 0x7FFFFFFF;

int N;
int sol[80 + 10];
int q[80 + 10];
int chk = 0;

void print(void)
{
	int i;
	for (i = 1; i <= N; i++)
	{
		printf("%d ", q[i]);
	}
	printf("\n");
}

int Check(int *a)
{
	int i, j;
	int len = 0;
	int flag = 0;
	int right = 0;
	int left = 0;

	// 좋은 수열인지 체크
	for (i = 1; a[i] != 0; i++) len++;
	for (i = 1; i < len; i++)
	{
		if (a[i] == a[len])
		{
			right = len;
			left = i;

			while (right != i)
			{
				right--;
				left--;
				if (a[right] != a[left]) break;
			}
			if (right == i) return 1;
		}
	}
	return 0;
}

int DFS(int n)
{
	if (chk == 1) return;
	if (Check(q) == 1) return;
	
	if (n > N)
	{
		//print();
		int i;
		for (i = 1; i <= N; i++)
		{
			sol[i] = q[i];
		}
		chk = 1;
		return;
	}

	q[n] = 1;
	DFS(n + 1);
	q[n] = 0;

	q[n] = 2;
	DFS(n + 1);
	q[n] = 0;

	q[n] = 3;
	DFS(n + 1);
	q[n] = 0;
}

void set(void)
{
	int i;
	for (i = 1; i <= N; i++)
	{
		sol[i] = INF;
	}
}

void main(void)
{
	scanf("%d", &N);

	set();
	DFS(1);

	int i;
	for (i = 1; i <= N; i++)
	{
		printf("%d", sol[i]);
	}
}

#endif