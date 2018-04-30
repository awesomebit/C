#include <stdio.h>

int N;//가로크기

int board[10010][20];//게임판

int block[4][4];//블럭

int pos;//block 위치

int ans;//쌓인 높이

inline void turnArr(int tmp[4][4]){

	int arr[4][4]; register int i, j;

	for (i = 0; i < 3; i++){

		for (j = 0; j < 3; j++){

			arr[j][2 - i] = tmp[i][j];//90도 회전

		}

	}

	for (i = 0; i < 3; i++){

		for (j = 0; j < 3; j++){

			tmp[i][j] = arr[i][j];

		}

	}

}

void makeBlock(){

	int tmp[4][4] = { 0 }; register int i, j; int turn;

	for (i = 0; i < 3; i++){//1.블럭정보받기

		for (j = 0; j < 3; j++){

			scanf("%d", &tmp[i][j]);

		}

	}

	scanf("%d %d", &turn, &pos);

	turn &= 3;//2.회전, turn %= 4;

	while (turn--) turnArr(tmp);//90도씩 회전

	for (i = 0; i < 3; i++){//3.상하반전해서저장, 배열은 0번부터이므로

		for (j = 0; j < 3; j++){

			block[2 - i][j] = tmp[i][j];

		}

	}

	while (block[0][0] + block[1][0] + block[2][0] == 0){//4.왼쪽벽에 붙이기

		for (i = 0; i < 3; i++){

			for (j = 0; j < 3; j++){

				block[i][j] = block[i][j + 1];

			}

		}

	}

	while (block[0][0] + block[0][1] + block[0][2] == 0){//5.아래벽에 붙이기

		for (i = 0; i < 3; i++){

			for (j = 0; j < 3; j++){

				block[i][j] = block[i + 1][j];

			}

		}

	}

	int width = 3;//6.오른쪽으로 이동(실제로는 시작위치만 계산)

	if (block[0][2] + block[1][2] + block[2][2] == 0){

		width--;

		if (block[0][1] + block[1][1] + block[2][1] == 0){

			width--;

		}

	}

	if (pos + width > N) pos = N - width;

}

inline int collision(int row){

	register int i, j;

	for (i = 0; i < 3; i++){

		for (j = 0; j < 3; j++){

			if (board[row + i][pos + j] && block[i][j]) return 1;//collision발생

		}

	}

	return 0;

}

void dropBlock(){

	register int row; register int i, j, a, b;

	for (row = ans; row > 0; row--) if (collision(row)) break;

	row++;

	for (i = 0; i < 3; i++){

		for (j = 0; j < 3; j++) board[row][pos + j] += block[i][j];

		for (j = 0; (j < N) && board[row][j]; j++);//완성되었는지 체크

		if (j == N){//한줄완성, row 줄 제거

			for (a = row; a <= ans; a++){

				for (b = 0; b < N; b++){

					board[a][b] = board[a + 1][b];

				}

			}

			ans--;

		}

		else row++;

	}

	if (ans < row) ans = row;

	for (; ans > 0; ans--){

		for (j = 0; (j < N) && !board[ans][j]; j++);//한줄이 모두 비었는지 체크

		if (j < N) break;//비어있지 않으므로 정지

	}

}

void output(int idx){

	printf("******************stage : %d******************\n", idx);

	for (register int i = ans; i > 0; i--){

		for (register int j = 0; j < N; j++){

			printf("%d", board[i][j]);

		}

		printf("\n");

	}

}

int main(){

	int M; register int i;

	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++){

		makeBlock();//블럭정보받기

		dropBlock();//블럭떨어트리기

		//output(i + 1);//디버깅, board상황 출력

	}

	printf("%d\n", ans);

	return 0;

}