
///////////////////////////////////////////////
//문제 번호 D: [LAB] 최고의 수식을 찾아라!
///////////////////////////////////////////////
#if 01
#include <stdio.h>
#pragma warning (disable:4996)

int N;

// 1, 2, 4, 8, 16, 32, 64 의 가치
int wi[7];	// 2의 제곱수 4개 이하 사용 시 가치
int vi[7];	// 2의 제곱수 5개 이상 사용 시 가치
int ai;		// 항 하나당 추가 가치

int set[] = { 1, 2, 4, 8, 16, 32, 64 };
int chk[7];	// 2의 제곱수 사용 횟수

int value;
int sol;
int s[7];

int checkHang(void)
{
	int i;
	int ret = 0;
	for (i = 0; i < 7; i++)
	{
		ret += chk[i];
	}
	return ret;
}

void DFS(int n, int sum)
{
	// 가지치기
	if (sum > N) return;

	// 종료조건
	if (sum == N)
	{
		value = 0;
		
		for (int k = 0; k < 7; k++)
		{
			if (chk[k] >= 5) value += (chk[k] * vi[k]);
			else value += (chk[k] * wi[k]);
		}
		value += (ai * checkHang());

		if (value > sol)
		{
			sol = value;
			for (int l = 0; l < 7; l++) s[l] = chk[l];
		}
		return;
	}
		
	for (int i = n; i < 7; i++)
	{
		chk[i]++;
		DFS(i, sum + set[i]);
		chk[i]--;
	}

}

int main(void)
{
	scanf("%d", &N);
	int i;
	for (i = 0; i < 7; i++) scanf("%d ", &wi[i]);
	for (i = 0; i < 7; i++) scanf("%d ", &vi[i]);
	scanf("%d", &ai);

	DFS(0, 0);
	
	// 1) 가장 가치가 높은 수식의 가치 출력
	// 2) 그 수식에서 2의 제곱수 사용횟수 구분 출력
	printf("%d\n", sol);
	for (i = 0; i < 7; i++) printf("%d ", s[i]);

	return 0;
}
#endif

