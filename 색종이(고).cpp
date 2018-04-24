#include <stdio.h>
//시간복잡도 0(N^6)
int N;	//색종이 수
int paper[110][110];	//테스트케이스 여러개면 반드시 초기화.

inline void FillPaper(int sr, int sc, int er, int ec)
{
	register int i, j;
	for (i = sr; i < er; i++)
	{
		for (j = sc; j < ec; j++)
		{
			paper[i][j] = 1;
		}
	}
}

void InputData()
{
	int r, c;
	scanf("%d", &N);
	for (register int i = 0; i < N; i++)
	{
		scanf("%d %d", &c, &r);
		FillPaper(r, c, r + 10, c + 10);
	}
}

inline int calArea(int sr, int sc, int er, int ec)
{
	register int i, j, area = 0;
	for (i = sr; i <= er; i++)
	{
		for (j = sc; j <= ec; j++)
		{
			if (paper[i][j] == 0) return 0;
			area++;
		}
	}
	return area;
}

int solve1()
{
	register int sr, sc, er, ec, max = 100;
	for (sr = 0; sr < 100; sr++)
	{ //시작 위치 세로 좌표
		for (sc = 0; sc < 100; sc++)
		{ //시작 위치 가로 좌표
			if (paper[sr][sc] == 0) continue; //색종이 없음, skip
			for (er = 0; er < 100; er++)
			{ //끝위치 세로 좌표
				for (ec = 0; ec < 100; ec++)
				{ //끝위치 가로 좌표
					if (paper[er][ec] == 0) continue; //색종이 없음, skip
					if (max >= (er - sr + 1) * (ec - sc + 1)) continue; //이전 답보다 작으면 skip
					int area = calArea(sr, sc, er, ec);
					if (max < area) max = area;
				}
			}
		}
	}
	return max;
}

inline void calH()
{
	register int i, j;
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (paper[i][j] == 0) continue;
			paper[i][j] += paper[i - 1][j];
		}
	}
}

int solve2()
{
	register int r, c, k, max = 100;
	calH;	//높이 구하기 O(N^2)
	for (r = 0; r < 100; r++)
	{
		for (c = 0; c < 100; c++)	//가로 시작 위치
		{
			if (paper[r][c] == 0) continue;	//시작위치에 색종이 없음
			int h = 100, area = 0;
			for (k = c; k < 100; k++)	//가로 끝위치
			{
				if (paper[r][k] < h) h = paper[r][k];	//낮은 높이 선택
				area = h * (k - c + 1);
				if (max < area) max = area;
			}
		}
	}
}

int main(){
	InputData();
	int ans = solve2();
	printf("%d\n", ans);
}