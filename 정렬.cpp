#include <stdio.h>

int N, C;
int Arr[100000 + 10];
int trr[100000 + 10];

void inputData()
{
	scanf("%d %d", &N, &C);
	for (register int i = 0; i < N; i++)
	{
		scanf("%d", &Arr[i]);
	}
}

void mergeSort1(int *arr, int s, int e)
{
	if (s >= e) return;
	int m = (s + e) / 2, i = s, j = m + 1, k = s;
	mergeSort1(arr, s, m);
	mergeSort1(arr, m + 1, e);
	while ((i <= m) && (j <= e))
	{
		if (arr[i] <= arr[j])	// 오름차순
		{
			trr[k++] = arr[i++];
		}
		else trr[k++] = arr[j++];
	}
	while (i <= m) trr[k++] = arr[i++];
	while (j <= e) trr[k++] = arr[j++];
	for (i = s; i <= e; i++) arr[i] = trr[i];
}

void mergeSort2(int *arr, int s, int e)
{
	if (s >= e) return;
	int m = (s + e) / 2, i = s, j = m + 1, k = s;
	mergeSort2(arr, s, m);
	mergeSort2(arr, m + 1, e);
	while ((i <= m) && (j <= e))
	{
		if (arr[i] >= arr[j])	// 내림차순
		{
			trr[k++] = arr[i++];
		}
		else trr[k++] = arr[j++];
	}
	while (i <= m) trr[k++] = arr[i++];
	while (j <= e) trr[k++] = arr[j++];
	for (i = s; i <= e; i++) arr[i] = trr[i];
}

void printData()
{
	for (register int i = 0; i < N; i++)
	{
		printf("%d\n", Arr[i]);
	}
}

int main()
{
	inputData();
	if (C == 0) mergeSort1(Arr, 0, N - 1);
	else if (C == 1) mergeSort2(Arr, 0, N - 1);
	printData();

	return 0;
}