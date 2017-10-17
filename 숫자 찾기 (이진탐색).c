///////////////////////////////////////////
//문제 번호 R: [TST] 숫자 찾기 (이진탐색)
///////////////////////////////////////////
#if 0
#include <stdio.h>

int N;
int a[50000 + 10];
int T;
int b[10000 + 10];


int binarySearch(int x, int y, int n)
{
	int mid = (x + y) / 2;
	if (a[mid] == n) return mid + 1;
	if (x >= y) return 0;
	if (a[mid] > n) binarySearch(x, mid - 1, n);
	else binarySearch(mid + 1, y, n);
}

void main(void)
{
	scanf("%d", &N);
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d", &b[i]);
	}

	for (i = 0; i < T; i++)
	{
		printf("%d\n", binarySearch(0, N - 1, b[i]));
	}

}
#endif