////////////////////////////////////////////////////
//문제 번호 : [TST]주사위 던지기2
////////////////////////////////////////////////////
// 백트래킹 기법 DFS: 깊이 우선으로 모든 경우를 탐색.
#if 0
#include <stdio.h>

int N, M;
int sum;
int s[7+10];

int DFS(int n, int sum)
{
	//종료조건: n에 관련해서
	int i;
	if (n > N)
	{
		if (sum == M)
		{
			for (i = 1; i <= N; i++)
			{
				printf("%d ", s[i]);
			}
			printf("\n");
		}
		return;
	}

	for (i = 1; i <= 6; i++)
	{
		s[n] = i;
		DFS(n + 1, sum + i);	
		// 개별적으로 해야. 전역, ++연산자 +=연산자 등 사용 X.
	}
}

void main(void)
{
	scanf("%d %d", &N, &M);

	DFS(1, 0);
}
#endif