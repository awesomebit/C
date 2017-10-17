///////////////////////////////////////////////
//문제 번호 A: [TST]소수와 함께 하는 여행
///////////////////////////////////////////////
#if 01
#include <stdio.h>

#define ABS(x) (((x)>0) ? (x) : -(x)) 
#define INF 0x7fffffff
#define QUE 10000;
typedef struct st
{
	int start, end, dist;
}SET;
SET q[10000];
int N1, N2;
int prime[10000+10];
int chk[10000 + 10];
int p;
int wp, rp;
int sol = INF;

void findPrimeNum(void)
{
	int flag = 0;
	int i, j;
	int n;
	for (n = 1000; n <= 9999; n++)
	{
		// search prime number and insert to array a.
		flag = 0;
		for (i = 2; i < n; i++)
		{
			if (n%i == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			prime[p++] = n;
			if (n == N1) chk[p - 1] = 1;
		}
	}
}

int Check(int n1, int n2)
{
	int tmp1 = n1;
	int tmp2 = n2;
	int cnt = 0;
	
	int k;
	for (k = 0; k < 4; k++)
	{
		if ((tmp1 % 10) - (tmp2 % 10) != 0) cnt++;
		tmp1 /= 10;
		tmp2 /= 10;
	}

	if (cnt > 1) return 0;
	else return 1;
}

void BFS(void)
{
	int ts, te, td;
	int ns, ne, nd;

	//init que
	chk[0] = 1;
	int k;
	for (k = 0; k < p; k++)
	{
		if (Check(N1, prime[k]) == 1)
		{
			q[wp].start = N1;
			q[wp].end = prime[k];
			q[wp++].dist = 1;
			chk[k] = 1;
			wp %= QUE;
		}
	}

	//deque;
	for (;;)
	{
		if (wp == rp) return;

		ts = q[rp].start;
		te = q[rp].end;
		td = q[rp++].dist;
		rp %= QUE;
		
		if (te == N2)
		{
			if (sol > td) sol = td;
		}

		for (k = 0; k < p; k++)
		{
			if (!(Check(te, prime[k]))) continue;
			if (chk[k]) continue;

			q[wp].start = te;
			q[wp].end = prime[k];
			q[wp++].dist = td + 1;
			chk[k] = 1;
			wp %= QUE;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N1, &N2);
	findPrimeNum();
	
	BFS();
	printf("%d", sol);
}
#endif
