///////////////////////////////////////////////////
//연산자 끼워넣기
///////////////////////////////////////////////////
#if 01
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int num[110]; 
int op[4];
//연산자 순서: 덧셈, 뺄셈, 곱셈, 나눗셈의 개수
#define INF 0x7fffffff
#define nINF 0x80000000
int max = nINF;
int min = INF;

void input(void)
{
	scanf("%d", &N);
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}
	for (i = 0; i < 4; i++)
	{
		scanf("%d", &op[i]);
	}
}

int DFS(int n, int sum)
{
	// 종료조건
	if (n >= N - 1)
	{
		if (sum > max) max = sum;
		if (sum < min) min = sum;
		return 0;
	}

	int i;
	for (i = 0; i < 4; i++)
	{
		if (op[i] == 0) continue;
		op[i]--;

		int tmp_sum;
		switch (i)
		{
		case 0: tmp_sum = sum + num[n + 1]; goto back;
		case 1: tmp_sum = sum - num[n + 1]; goto back;
		case 2: tmp_sum = sum * num[n + 1]; goto back;
		case 3: tmp_sum = sum / num[n + 1]; goto back;
		}

		back:
		DFS(n + 1, tmp_sum);
		op[i]++;
	}
}

void solve(void)
{
	DFS(0, num[0]);
}

int main(void)
{
	input();
	solve();

	printf("%d\n%d", max, min);

	return 0;
}
#endif
