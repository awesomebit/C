///////////////////////////////////////////////
//문제 번호 E: [TST]택배
///////////////////////////////////////////////
#if 01
#include <stdio.h>

typedef struct st
{
	int snd;	// 보내는 마을번호
	int rcv;	// 받는 마을번호
	int box;	// 박스 개수
}SET;
SET q[10000 + 10];
int load[10000 + 10];
int N, C;	// 마을의 수 N, 트럭의 용량 C
int M;		// 보내는 박스 정보의 개수 M
int sol;

void GREEDY(void)
{
	int i, j;
	for (i = 1; i <= M; i++)
	{
		int get = 0;
		int from = q[i].snd;
		int to = q[i].rcv;
		int box = q[i].box;

		// 현재 상태에서 적재할 수 있는 최대 load값을 구한다.
		for (j = from; j < to; j++)
		{
			if (get < load[j]) get = load[j];
		}

		// 최대용량보다 크다면 최대용량까지만 적재한다.
		if (C - get < box) get = C - get;
		else get = box;

		// 적재할 용량을 sol값에 저장.
		sol += get;

		// load배열을 업데이트한다.
		for (j = from; j < to; j++)
		{
			load[j] += get;
		}
	}
}

void sort(void)
{
	int i, j;
	SET tmp;
	for (i = 1; i < M; i++)
	{
		for (j = i; j <= M; j++)
		{
			if (q[j].rcv < q[i].rcv)
			{
				tmp = q[i];
				q[i] = q[j];
				q[j] = tmp;
			}
			if (q[j].rcv == q[i].rcv && q[j].snd < q[i].snd)
			{
				tmp = q[i];
				q[i] = q[j];
				q[j] = tmp;
			}
		}
	}
}

void main(void)
{
	scanf("%d %d", &N, &C);
	scanf("%d", &M);

	for (int i = 1; i <= M; i++) scanf("%d %d %d", &q[i].snd, &q[i].rcv, &q[i].box);

	// 도착지를 기준으로 오름차순으로 정렬한다.
	// 출발지를 기준으로 하면 예외조건이 너무 많음.
	sort();
	GREEDY();

	printf("%d", sol);
}
#endif
