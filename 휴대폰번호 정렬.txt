///////////////////////////////////////////
//문제 번호 X: [TST]휴대폰번호 정렬
///////////////////////////////////////////
#if 0
#include <stdio.h>

typedef struct 
{
	int n1, n2, n3, digit;
}P_t;

P_t a[50 + 10];

int N;
int P[10 + 10];
char str[50 + 10][13 + 10];

int cmp(int i, int j)
{
	// 오름차순은 -1 리턴.
	if (P[a[i].n1 % 10] < P[a[j].n1 % 10]) return -1;
	if (P[a[i].n1 % 10] > P[a[j].n1 % 10]) return 1;

	// 위가 같으면 다음으로 이동.
	if (a[i].digit > a[j].digit) return -1;
	if (a[i].digit < a[j].digit) return 1;

	if (a[i].n2 < a[j].n2) return -1;
	if (a[i].n2 > a[j].n2) return 1;

	if (a[i].n3 < a[j].n3) return -1;
	if (a[i].n3 > a[j].n3) return 1;
}

void main(void)
{
	scanf("%d", &N);
	int i, j, d;
	P_t temp;
	// 우선순위를 P배열에 정리.

	for (i = 1; i <= 6; i++)
	{
		scanf("%d", &d);
		P[d] = i;
	}

	// 문자열로 받아서
	for (i = 0; i < N; i++)
	{
		scanf("%s", &str[i][0]);
	}

	// sscanf 로 int로 재정리.
	for (i = 0; i < N; i++)
	{
		sscanf(str[i], "%d-%d-%d", &a[i].n1, &a[i].n2, &a[i].n3);
		if (str[i][12] == '\0') a[i].digit = 3;
		else a[i].digit = 4;
	}

	// 중간번호 오름차순
	// 4자리수 우선, 3자리수 나중.
	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (cmp(i, j) == 1)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		if (a[i].digit == 3) printf("%03d-%03d-%04d\n", a[i].n1, a[i].n2, a[i].n3);
		else printf("%03d-%04d-%04d\n", a[i].n1, a[i].n2, a[i].n3);
	}

	// 끝번호 오름차순


}
#endif