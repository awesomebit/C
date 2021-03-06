#include <stdio.h>
#include <stdlib.h>


#define FAILED (-1)
int data[10] = {1,3,5,7,9,11,13,15,17,19};


int Binary_Search_Lower(int s, int e, int d)
{
	int m, sol = FAILED;

	while (s<=e)
	{
		m = (s + e) / 2;
		if (data[m] >= d)
		{
			sol = m;
			e = m - 1;
		}
		else s = m + 1;
	}
	return sol;
}

int Binary_Search_Upper(int s, int e, int d)
{
	int m, sol = FAILED;

	while (s <= e)
	{
		m = (s + e) / 2;
		if (data[m] <= d)
		{
			sol = m;
			s = m + 1;
		}
		else e = m - 1;
	}
	return sol;
}

int main(void)
{
	int i;
	int lower, upper;

	// 4~16 범위의 data 갯수 찾기
	lower = Binary_Search_Lower(0, 9, 4);
	if (lower != FAILED)
	{
		upper = Binary_Search_Upper(0, 9, 16);
		printf("%d\n",upper-lower+1);
	}
	else printf("0\n");



	return 0;
}
