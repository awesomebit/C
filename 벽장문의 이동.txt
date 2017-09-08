////////////////////////////////////////////
//문제 번호 : [TST] 벽장문의 이동 
////////////////////////////////////////////
#if 0
#include <stdio.h>

int T;				//벽장의 개수
int L, R;			//열려있는 두개의 벽장
int N;				//벽장이 열리는 순서의 길이
int a[20 + 10];		//열리는 순서
int sol = 0x7fffffff;

#define ABS(x) ((x)>0?(x):-(x))

void DFS(int n, int cnt, int l, int r)
{
	if (sol <= cnt) return;
	if (n > N)
	{
		if (sol > cnt) sol = cnt;
		return;
	}
	DFS(n + 1, cnt + ABS(l - a[n]), a[n], r);	//왼쪽
	DFS(n + 1, cnt + ABS(r - a[n]), l, a[n]);	//오른쪽
}

int main(void)
{
	scanf("%d", &T);
	scanf("%d %d", &L, &R);
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
	}
	
	DFS(1, 0, L, R);

	printf("%d", sol);

	return 0;
}

#endif