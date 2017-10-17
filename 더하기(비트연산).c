////////////////////////////////////////////////////
//문제 번호 : [TST] 더하기 (비트연산 루프 사용)
////////////////////////////////////////////////////
#if 0
#include <stdio.h>

int T;
int N, K;
int di[20 + 10];

int find(void)
{
	int sum = 0;
	int bit;
	int sol = 0;
	int i;

	for (bit = 0; bit < (1 << N); bit++)
	{ 
		sum = 0;
		for (i = 0; i < N; i++)
		{
			if (bit & (1 << i)) sum += di[i];
		}
		if (sum == K) return 1;
	} 
	return 0;

	if (sol) printf("YES\n");
	else printf("NO\n");

}

void main(void)
{
	scanf("%d", &T);
	int i, j;
	while (T--)
	{
		scanf("%d %d", &N, &K);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &di[i]);
		}

		if (find()) printf("YES\n");
		else printf("NO\n");
	}
}
#endif