////////////////////////////////////////////////////
//���� ��ȣ : [TST]�ڵ������ִ�ȸ(BASIC2)
////////////////////////////////////////////////////
#if 0
#include <stdio.h>

int D;
int N;
int d[50 + 10];	//������ ����� ������ �Ÿ�
int t[50 + 10];	//����� �� ���� �ð�
int sol = 9999;

int DFS(int n, int sum, int dist)
{
	// ����ġ��� �� ����.
	if (sol <= sum) return;

	// ��������.
	if (n > N)
	{
		if (sol > sum)
		{
			sol = sum;
		}
		return;
	}

	// ���� �޴� ���
	DFS(n + 1, sum + t[n], d[n]);
	//���� ���� �ʴ� ���
	if (dist + d[n] <= D)
	{
		DFS(n + 1, sum, dist + d[n]);
	}
	// ���ƿ� �ʿ䰡 ��� chk�迭�� �ʿ����.
}

void main(void)
{
	scanf("%d", &D);
	scanf("%d", &N);
	int i;
	for (i = 0; i <= N; i++)
	{
		scanf("%d", &d[i]);
	}
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &t[i]);
	}

	DFS(1, 0, d[0]);
	printf("%d", sol);
}
#endif