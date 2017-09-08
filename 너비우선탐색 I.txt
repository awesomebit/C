////////////////////////////////////////////
//문제 번호 : [TST]너비우선탐색Ⅰ
////////////////////////////////////////////
#if 01
#include <stdio.h>

typedef struct
{
	int s, e;
}GAME;

GAME Q[200 + 10];

int N, M;	//정점, 간선

int chk[100 + 10];
int queue[100 + 10];

int ns, ne;
int wp, rp;
int temp;

int BFS(void)
{
	chk[1] = 1;
	queue[wp++] = 1;

	while (wp > rp)
	{
		int k;

		temp = queue[rp++];

		for (k = 0; k < M; k++)
		{
			ns = Q[k].s;
			ne = Q[k].e;

			if (ns == temp && chk[ne] == 0)
			{
				chk[ne] = 1;
				queue[wp++] = ne;
			}
			if (ne == temp && chk[ns] == 0)
			{
				chk[ns] = 1;
				queue[wp++] = ns;
			}
		}
	}
}


void main(void)
{
	scanf("%d %d", &N, &M);
	int i;
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &Q[i].s, &Q[i].e);
	}

	BFS();

	for (i = 0; i < N; i++)
	{
		printf("%d ", queue[i]);
	}
}
#endif