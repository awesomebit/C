////////////////////////////////////////////////////
//문제 번호 : [TEST] 책꽂이
////////////////////////////////////////////////////
#if 0
#include <stdio.h>

int T;	//테스트케이스 
int N;	//소의 마리수
int B;	//책꽂이 높이
int H[20 + 10];
int chk[20 + 10];
int min = 0x7fffffff;

int DFS(int n, int sum)
{
	if (min < sum) return;

	if (n > N)
	{
		if (sum >= B)
		{
			if (min > sum)
			{
				min = sum;
				return;
			}
		}
		return;
	}

	if (chk[n] == 1) return;

	chk[n] = 1;
	DFS(n + 1, sum + H[n]);
	DFS(n + 1, sum);
	chk[n] = 0;

}

void main(void)
{	
	int i, j;
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &B);
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &H[j]);
		}

		min = 0x7fffffff;
		DFS(1, 0);
		printf("%d\n", min - B);
	}
}
#endif