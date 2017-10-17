////////////////////////////////////////////
//문제 번호 B: [TEST] 선거 DFS
////////////////////////////////////////////
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 5
#define DIRS 4
#define POS_IS_J (map[r][c] == 'J')

int T, sol, fillcnt;
char map[SIZE][SIZE];
int vis[SIZE][SIZE];
int fill_vis[SIZE][SIZE];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void Init(void){
	sol = 0;
	memset(&vis[0][0], 0, sizeof(int[SIZE][SIZE]));
	memset(&map[0][0], 0, sizeof(int[SIZE][SIZE]));
}

void Input_Data(){
	int i;
	for (i = 0; i < SIZE; i++)
	{
		scanf("%s", &map[i][0]);
	}
}

void Fill(int i, int j){
	int k, ni, nj;
	if (fill_vis[i][j]) return;
	
	fill_vis[i][j] = 1;

	for ( k = 0; k < DIRS; k++)
	{
		ni = i + di[k]; nj = j + dj[k];
		if (ni < 0 || ni > 4 || nj < 0 || nj > 4) continue;
		if (fill_vis[ni][nj] || vis[ni][nj] == 0) continue;	
		Fill(ni, nj);
	}
}

int Cal_Area(){
	int i, j;
	for ( i = 0; i < SIZE; i++)
	{
		for ( j = 0; j < SIZE; j++)
		{
			if (fill_vis[i][j]) fillcnt++;
		}
	}
	return fillcnt;
}

// 색칠한 영역의 개수가 7이면 0 아니면 1
int Start_Fill_And_Cal_Area(){
	int i, j;
	fillcnt = 0;
	memset(fill_vis, 0, sizeof(int[SIZE][SIZE]));

	// flood fill
	for ( i = 0; i < SIZE; i++){
		for ( j = 0; j < SIZE; j++){
			if (vis[i][j] == 0) continue;
			Fill(i, j);
			if (Cal_Area() == 7) 
				return 0;
			return 1;
		}
	}
	return 1;
}

void DFS(int n, int numJ, int numH, int idx){
	int i, r, c;

	if (n > 7){
		if (Start_Fill_And_Cal_Area()) return;
		if (numJ > numH) 
			sol++;
		return;
	}

	for (i = idx + 1; i < SIZE*SIZE; i++)
	{
		r = i / 5;
		c = i % 5;
		if (vis[r][c]) continue;
		vis[r][c] = 1;
		if (POS_IS_J) { 
			DFS(n + 1, numJ + 1, numH, i); 
		} else {
			DFS(n + 1, numJ, numH + 1, i); 
		}
		vis[r][c] = 0;
	}
}

int main(void){

	scanf("%d", &T);
	while (T--)
	{
		Init();
		Input_Data();
		DFS(1, 0, 0, -1);
		printf("%d\n", sol);
	}
	
	return 0;
}


#endif
