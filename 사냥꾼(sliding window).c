//////////////////////////////////////////////////////
//문제 번호 D: [TST]사냥꾼 sliding window
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


// qsort 써야함 
void sort(void)
{
	int i, j;
	int tmp;
	for (i = 0; i < M; i++)
	{
		for (j = i + 1; j < M + 1; j++)
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

// sliding window
int solve(void)
{
	int i, right = 0;
	int cnt = 0;

	for (i = 0; i < N; i++)
	{
		//오른쪽 사대 확인 후 왼쪽 사대 확인
		while (right < M && gun[right] < a[i].x) right++;
		if (right < M && a[i].y + gun[right] - a[i].x <= L) 
			cnt++;
		else if (right > 0 && a[i].y + a[i].x - gun[right - 1] <= L) 
			cnt++;
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
