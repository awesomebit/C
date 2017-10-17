#include <stdio.h>

int N;
int paper[128][128];
int cnt[2];

void Input_Data(void)
{
	int r, c;
	scanf("%d",&N);
	for (r = 0; r < N;r++)
	{
		for (c = 0; c < N;c++)
		{
			scanf("%d",&paper[r][c]);
		}
	}
}

void Count_Paper(int sr, int sc, int size)
{
	int color,r,c,er,ec;
	
	color = paper[sr][sc];
	er = sr + size - 1;
	ec = sc + size - 1;

	for (r = sr; r <= er ;r++)
	{
		for (c = sc; c <= ec;c++)
		{
			if (paper[r][c] != color) goto END_OF_LOOP;
		}
	}

END_OF_LOOP:
	if (r == er + 1) cnt[color]++;
	else
	{
		Count_Paper(sr, sc, size/2);
		Count_Paper(sr, sc + (size / 2), size / 2);
		Count_Paper(sr + (size / 2), sc, size / 2);
		Count_Paper(sr + (size / 2), sc + (size / 2), size / 2);
	}
}


int main(void)
{
	Input_Data();

	Count_Paper(0,0,N);

	printf("%d\n%d\n",cnt[0],cnt[1]);

	return 0;
}
