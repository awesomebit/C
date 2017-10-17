////////////////////////////////////////
//Quick Sort
////////////////////////////////////////
#if 01
#include <stdio.h>
#include <stdlib.h>

int data[4] = { 4, 2, 3, 1 };
int tmp[4];

int comp(const int* p1, const int* p2)
{
	return *p1 - *p2;
}

void main(void)
{
	qsort(data, sizeof(int), 4, comp);

	int i;
	for (i = 0; i < 4; i++)
	{
		printf("%d ", data[i]);
	}
}
#endif