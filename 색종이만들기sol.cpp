//Problem A solution


#include <stdio.h>

int N;//지도 크기

int A[130][130];//색종이

int cnt[2];//각 색종이 개수 파악

void InputData(){

	scanf("%d", &N);

	for (register int i = 0; i < N; i++){

		for (register int j = 0; j < N; j++){

			scanf("%d", &A[i][j]);

		}

	}

}

inline int check(int r, int c, int len, int color){

	for (register int i = r; i < r + len; i++){

		for (register int j = c; j < c + len; j++){

			if (A[i][j] != color) return 0;//같은 색 아님

		}

	}

	return 1;//모두 같은 색임

}

void dq(int r, int c, int len){

	if (check(r, c, len, A[r][c])){//모두 같은색인경우

		cnt[A[r][c]]++;

		return;

	}

	int m = len / 2;

	dq(r, c, m); dq(r, c + m, m);

	dq(r + m, c, m); dq(r + m, c + m, m);

}

int main(){

	InputData();

	cnt[0] = cnt[1] = 0;

	dq(0, 0, N);

	printf("%d\n%d\n", cnt[0], cnt[1]);

	return 0;

}