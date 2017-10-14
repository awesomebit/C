//////////////////////////////////////////////////////
//문제 번호 C: [TST]회전 초밥(중)
//////////////////////////////////////////////////////
#if 01
#include <stdio.h>

int N, d, k, c;
int food[30000 + 10];
int chk[3000 + 10];
int count;
int sol;

void initCount(void)
{
	int i;
	for (i = 0; i < k; i++)
	{
		if (chk[food[i]] == 0) count++;
		chk[food[i]]++;
	}
	sol = count;
}

void function(void)
{
	int i;
	int tmp;
	for (i = 0; i < N; i++)
	{
		// 첫번째 초밥 빼주기
		chk[food[i]]--;
		if (chk[food[i]] == 0) count--;

		// 새로운 초밥 더해주기
		tmp = (i + k) % N;
		if (chk[food[tmp]] == 0) count++;
		chk[food[tmp]]++;

		// sol 갱신하기
		if (sol <= count)
		{
			sol = count;
			if (chk[c] == 0) sol++;
		}
	}
}

void main(void)
{
	scanf("%d %d %d %d", &N, &d, &k, &c);
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &food[i]);
	}

	initCount();
	function();

	printf("%d", sol);
}
#endif
