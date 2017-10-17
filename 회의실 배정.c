/////////////////////////////////////////
//문제 번호 : [TST]회의실 배정
/////////////////////////////////////////
#if 01
#include <stdio.h>

typedef struct st
{
	int num;
	int start;
	int end;
}SET;
SET q[500 + 10];
int N;
int sel[500 + 10];
int n = 1;

void sort(void)
{
	int i, j;
	SET tmp;
	for (i = 1; i < N; i++)
	{
		for (j = i + 1; j <= N; j++)
		{
			// end 오름차순 정렬
			if (q[i].end > q[j].end)
			{
				tmp = q[j];
				q[j] = q[i];
				q[i] = tmp;
			}
			// end가 같다면 start 오름차순 정렬
			if (q[i].end == q[j].end && q[i].start > q[i].start)
			{
				tmp = q[j];
				q[j] = q[i];
				q[i] = tmp;
			}
		}
	}
}

void print(void)
{
	int i;
	for (i = 1; sel[i] != 0; i++)
	{
		printf("%d ", sel[i]);
	}
}

int GREEDY(void)
{
	int i;
	int start = q[1].start;
	for (i = 1; i <= N; i++)
	{
		if (start <= q[i].start)
		{
			start = q[i].end;
			sel[n++] = q[i].num;
		}
	}
	return n - 1;
}

void main(void)
{
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d %d", &q[i].num, &q[i].start, &q[i].end);
	}

	sort();
	printf("%d\n", GREEDY());
	print(); 
}
#endif
