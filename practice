// sorting numbers in array small to large
#if 0
#include <stdio.h>

a[10] = { 50, 40, 30, 20, 10, 55, 44, 33, 22, 11 };

void sorting(void)
{
	int i, j, k;
	int tmp = 0;

	for (i = 0; i < 10; i++)
	{
		for (j = i+1; j < 10; j++)
		{
			if (a[i] < a[i+1])
			{
				tmp = a[i];
				a[i] = a[i + 1];
				a[i+1] = tmp;
			}
		}
	}

	for (k = 0; k < 5; k++)
	{
		tmp = a[k];
		a[k] = a[9 - k];
		a[9 - k] = tmp;
	}

	for (k = 0; k < 10; k++)
	{
		printf("%d, ", a[k]);
	}
}

void main(void)
{
	sorting();
}

#endif


// finding prime integers in a number given
#if 1
#include <stdio.h>

void primeInt(void)
{
	int i, j, k;
	int num;
	int arr[100];
	int cnt = 0;
	scanf("%d", &num);
	
	for (i = 2; i <= num; i++)
	{
		for (j = 2; j <= num; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			arr[cnt] = i;
			cnt++;
		}
	}
	for (k = 0; k < cnt; k++)
	{
		printf("%d ", arr[k]);
	}
}

void main(void)
{
	primeInt();
}

#endif
