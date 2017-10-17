////////////////////////////////////////
//Merge Sort
////////////////////////////////////////
#if 01
#include <stdio.h>

int data[4] = { 4, 2, 3, 1 };
int tmp[4];

void merge(int s, int e, int m)
{
	int idx1, idx2, idxtmp;

	idx1 = s;
	idx2 = m + 1;
	idxtmp = s;

	while(idx1 <= m && idx2 <= e)
	{
		if (data[idx1] < data[idx2]) 
			tmp[idxtmp++] = data[idx1++];
		else
			tmp[idxtmp++] = data[idx2++];
	}

	if (idx1 <= m)
		while (idx1 <= m) tmp[idxtmp++] = data[idx1++];
	else
		while (idx2 <= e) tmp[idxtmp++] = data[idx2++];

	for (idxtmp = s; idxtmp <= e; idxtmp++)
		data[idxtmp] = tmp[idxtmp];

}

void mergeSort(int s, int e)
{
	int m;

	if (s >= e) return;

	m = (s + e) / 2;

	mergeSort(s, m);
	mergeSort(m + 1, e);

	merge(s, e, m);
}

void main(void)
{
	//mergeSort(int s, int e);
	mergeSort(0, 3);

	int i;
	for (i = 0; i < 4; i++)
	{
		printf("%d ", data[i]);
	}
}
#endif