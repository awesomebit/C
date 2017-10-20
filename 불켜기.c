////////////////////////////////////////////
//문제 번호 B: [TEST] 불켜기
////////////////////////////////////////////
#if 01
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int N, M;
int index[110][110];
int visited[110][110];
int light[110][110];
typedef struct
{
	int si, sj;
	int ei, ej;
}SWITCH;
SWITCH Q[20010];
int sol;
int sw_flag;

void inputData(void)
{
	int si, sj, ei, ej;
	int i;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++)
	{
		scanf("%d %d %d %d", &Q[i].si, &Q[i].sj, &Q[i].ei, &Q[i].ej);
	}
}

void init(void)
{
	memset(index, 0, sizeof(index));
	memset(visited, 0, sizeof(visited));
	memset(light, 0, sizeof(light));
	memset(Q, 0, sizeof(SWITCH[20010]));
}

int comp(const void * p1, const void * p2)
{
	if (((SWITCH*)p1)->si == ((SWITCH*)p2)->si)
		return ((SWITCH*)p1)->sj - ((SWITCH*)p2)->sj;
	return ((SWITCH*)p1)->si - ((SWITCH*)p2)->si;
}

void makeIndex(void)
{
	// index에 정리 (lut처럼 만들기)
	int n;
	for (n = 1; n <= M; n++)
	{
		if (Q[n].si != Q[n - 1].si || Q[n].sj != Q[n - 1].sj)
		{
			index[Q[n].si][Q[n].sj] = n;	
		}
	}
}

int floodfill(int i, int j)
{
	static int di[4] = { -1, 0, 1, 0 };
	static int dj[4] = { 0, 1, 0, -1 };
	int ni, nj;

	visited[i][j] = 1;

	// 한 번이라도 스위치를 안켜본 곳 이 있으면 스위치를 켜자
	int l;
	if (index[i][j])
	{
		sw_flag = 1;
		for (l = index[i][j]; l <= M; l++)
		{
			if (Q[l].si != i || Q[l].sj != j) break;
			if (light[Q[l].ei][Q[l].ej] == 0)
			{
				light[Q[l].ei][Q[l].ej] = 1;
				sol++;
			}
		}
		index[i][j] = 0;
	}
	
	// floodfill 재귀
	int k;
	for (k = 0; k < 4; k++)
	{
		ni = i + di[k];
		nj = j + dj[k];

		if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
		if (visited[ni][nj] == 1) continue;
		if (light[ni][nj] == 0) continue;
		
		floodfill(ni, nj);
	}
}

int solve(void)
{
	makeIndex();
	sw_flag = 1;
	sol = 1;
	light[1][1] = 1;

	while (sw_flag)
	{
		sw_flag = 0;
		memset(visited, 0, sizeof(visited));
		floodfill(1, 1);
	}
	return sol;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		inputData();
		qsort(Q + 1, M, sizeof(SWITCH), comp);
		printf("%d\n", solve());

		init();
	}
	return 0;
}
#endif
