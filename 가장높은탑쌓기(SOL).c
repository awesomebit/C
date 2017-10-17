//////////////////////////////////////////
//문제 번호 N: [TST]가장높은탑쌓기
//////////////////////////////////////////
#if 01
#include <stdio.h>
#include <stdlib.h>

int N;
typedef struct st
{
	int num;
	int area;
	int height;
	int weight;
}TOWER;
TOWER q[101];
int path[101];
int D[101];		//타워의 높이
int path[101];
int brick_cnt = 0;

void inputData(void)
{
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d %d", &q[i].area, &q[i].height, &q[i].weight);
		q[i].num = i;
	}
}

int comp(const TOWER* p1, const TOWER* p2)
{
	return p1->weight - p2->weight;
}

int findLIS(void)
{
	int n, k, lastidx = 0;
	
	for (n = 1; n <= N; n++)
	{
		for (k = 0; k < n; k++)
		{
			if (q[n].area > q[k].area && D[n] < D[k] + q[n].height)
			{
				D[n] = D[k] + q[n].height;
				path[n] = k;
			}
			if (D[n] > D[lastidx])
			{
				lastidx = n;
			}
		}
	}
	return lastidx;
}

void printPath(int idx)
{
	if (idx == 0)
	{
		printf("%d\n", brick_cnt);
		return;
	}
	brick_cnt++;
	printPath(path[idx]);
	printf("%d\n", q[idx].num);
}

int main(void)
{
	int lastidx; 
	inputData();
	qsort(&q[1], N, sizeof(TOWER), comp);
	lastidx = findLIS();
	printPath(lastidx);

	return 0;
}	
#endif
