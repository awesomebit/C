///////////////////////////////////////////
//문제 번호 : [TST]회전 초밥(중)	수정
///////////////////////////////////////////
#if 0
#include <stdio.h>

int N, d, k, c;
int a[30000 + 10];	//벨트 위 초밥의 나열 상태.
int cnt[3000 + 10];
int sol = 0;

void main(void)
{
	int i;
	int total = 1;

	scanf("%d %d %d %d", &N, &d, &k, &c);
	
	cnt[c]++;

	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < N + k - 1; i++)
	{
		if (++cnt[a[i%N]] == 1) total++;
		if (i >= k - 1)
		{
			if (sol < total) sol = total;
			if (--cnt[a[i - k + 1]] == 0) total--;
		}
	}

	printf("%d", sol);
}
#endif