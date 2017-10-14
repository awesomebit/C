//////////////////////////////////////////////////////
//문제 번호 D: [TST]사냥꾼 binary search
//////////////////////////////////////////////////////
#if 01
#include <stdio.h>

int M;	//사대의 수
int N;	//동물의 수
int L;	//사정거리
int gun[100000 + 10];	//gun 의 x좌표값
typedef struct st
{
	int x, y;
}ANIMAL;
ANIMAL a[100000 + 10];	//animal의 x,y좌표값
#define INF 0x7fffffff

// qsort 써야함 
void sort(void)
{
	int i, j;
	int tmp;
	for (i = 0; i < M - 1; i++)
	{
		for (j = i + 1; j < M; j++)
		{
			if (gun[i] > gun[j])
			{
				tmp = gun[j];
				gun[j] = gun[i];
				gun[i] = tmp;
			}
		}
	}
}

void inputData(void)
{
	scanf("%d %d %d", &M, &N, &L);
	int i;
	for (i = 0; i < M; i++) scanf("%d", &gun[i]);
	for (i = 0; i < N; i++) scanf("%d %d", &a[i].x, &a[i].y);
}

int binarySearchUpper(int s, int e, int target)
{
	int m;
	int sol = -1;

	while (s <= e)
	{
		m = (s + e) / 2;
		if (gun[m] <= target)
		{
			sol = m;
			s = m + 1;
		}
		else e = m - 1;
	}
	return sol;
}

int binarySearchLower(int s, int e, int target)
{
	int m;
	int sol = -1;

	while (s <= e)
	{
		m = (s + e) / 2;
		if (gun[m] >= target)
		{
			sol = m;
			e = m - 1;
		}
		else s = m + 1;
	}
	return sol;
}

int solve(void)
{
	int i;
	int cnt = 0;
	int ret;

	//loop
	for (i = 0; i < N; i++)
	{
		// 동물의 왼쪽에서 가장 큰 x좌표의 사대 검색
		ret = binarySearchUpper(0, M - 1, a[i].x);
		// 사대에서 동물을 잡을 수 있는지 조건
		if (ret != -1 && a[i].y + a[i].x - gun[ret] <= L) cnt++;
		else
		{
			// 동물이 왼쪽 사대의 사거리에 닿지 않는다면,
			// 동물의 오른쪽에서 가장 작은 x좌표의 사대 검색
			ret = binarySearchLower(0, M - 1, a[i].x);
			if (ret != -1 && a[i].y + gun[ret] - a[i].x <= L) cnt++;
		}
	}
	return cnt;
}

int main(void)
{
	inputData();
	sort();
	printf("%d", solve());

	return 0;
}
#endif
