///////////////////////////////////////////
//문제 번호 : [TST]회전 초밥(중)
///////////////////////////////////////////
#if 0
#include <stdio.h>

int N, d, k, c;
int a[30000 + 10];	//벨트 위 초밥의 나열 상태.
int chk[3000 + 10];
int sel[3000 + 10];
int sol = 0;

int function(int n)
{
	int flag = 0;
	int cnt = 0;
	int temp;
	int i, j, l;
	int m = 0;

	for (l = 1; l <= 3000; l++)
	{
		chk[l] = 0;
	}

	for (i = n; i < n + k; i++)
	{
		temp = i % N;
		sel[m++] = a[temp];
		chk[a[temp]] = 1;
	}

	for (j = 0; j <= 3000; j++)
	{
		if (chk[j] == 1) cnt++;
		if ((j == c) && (chk[j] == 1)) flag = 1;		
	}
	
	if (flag == 0) cnt+=1;

	return cnt;
}

void main(void)
{
	scanf("%d %d %d %d", &N, &d, &k, &c);
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < N; i++)
	{
		int tmp = function(i);
		if (sol < tmp) sol = tmp;
	}

	printf("%d", sol);

}
#endif