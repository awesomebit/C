////////////////////////////////////////
//소수찾기 알고리즘
////////////////////////////////////////
#if 01
#include <stdio.h>

int notPrime[10000 + 10];

void main(void)
{
	//에라토스테네스의 체 (소수찾기)
	int i, j;
	for (i = 2; i <= 9999; i++)
	{
		if (notPrime[i] == 0)
		{
			for (j = i + i; j <= 9999; j+=i)
			{
				notPrime[j] = 1;
			}
		}
	}

	printf("s");
	// notPrime배열에 0이면 소수임.
}
#endif
