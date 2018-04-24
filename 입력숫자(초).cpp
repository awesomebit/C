#include <stdio.h>
int N;
int Y[40];
int X[40];
void InputData()
{
	scanf("%d", &N);
	for (register int i = 0; i < N; i++){
		scanf("%d", &Y[i]);
	}
}
void OutputData()
{
	printf("%d\n", N);
	for (register int i = 0; i < N; i++)
	{
		printf("%d ", X[i]);
	}
	printf("\n");
}
int solve()
{
	int value = Y[0], idx = 0;
	for (register int i = 0; i < N; i++)
	{
		for (register int j = 0; j < N; j++)
		{
			if (X[idx] == 0) break;
			idx = (idx + 1) % N;
		}
		if (X[idx] != 0) return -1;	//복원실패, 사실 이런 경우 없음.
		X[idx] = Y[i];
		idx = (idx + Y[i]) % N;
	}
}
int main()
{
	InputData();
	int ans = solve();
	if (ans == -1) printf("-1\n");
	else OutputData();

	return 0;
})