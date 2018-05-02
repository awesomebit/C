#include <stdio.h>

int N;//가로크기

int board[10010 * 3];//게임판

int block[4];//블럭

int pos;//block 위치

int ans;//쌓인 높이

int mask;

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

	int orbits = 0;

	for (i = 0; i < 3; i++){//3.상하반전해서저장, 배열은 0번부터이므로

		block[2 - i] = 0;

		for (j = 0; j < 3; j++){

			block[2 - i] += (tmp[i][j] << j);

		}

		orbits |= block[2 - i];

	}

	while (!(orbits & 1)){//4.왼쪽벽에 붙이기(비트특성상 우로 shift)

		for (i = 0; i < 3; i++) block[i] >>= 1;

		orbits >>= 1;

	}

	while (!block[0]){//5.아래벽에 붙이기

		for (i = 0; i < 3; i++) block[i] = block[i + 1];

	}

	//6.오른쪽으로 이동(실제로 이동, 비트특성상 좌로 shift)

	int wall = ~mask;//벽

	for (i = 0; i < pos; i++){

		if ((orbits << 1) & wall) break;//0이 아니면 벽을 넘어감

		orbits <<= 1;

		for (j = 0; j < 3; j++) block[j] <<= 1;

	}

}

inline int collision(int row){

	register int i;

	for (i = 0; i < 3; i++){

		if (board[row + i] & block[i]) return 1;//collision발생

	}

	return 0;

}

void dropBlock(){

	register int row; register int i, a;

	for (row = ans; row > 0; row--) if (collision(row)) break;

	row++;

	for (i = 0; i < 3; i++){

		if (!block[i]) break;

		board[row] += block[i];

		if (board[row] == mask){//한줄완성, row 줄 제거

			for (a = row; a <= ans; a++) board[a] = board[a + 1];

			ans--;

		}

		else row++;

	}

	if (ans < row - 1) ans = row - 1;

}

void output(int idx){

	printf("******************stage : %d******************\n", idx);

	for (register int i = ans; i > 0; i--){

		for (register int j = 0; j < N; j++){

			printf("%d", (board[i] >> j) & 1);

		}

		printf("\n");

	}

}

int main(){

	int M; register int i;

	scanf("%d %d", &N, &M);

	mask = (1 << N) - 1;//한줄완성 확인용(0번비트부터 N개비트가 모두 1인 값 만들기)

	for (i = 0; i < M; i++){

		makeBlock();//블럭정보받기

		dropBlock();//블럭떨어트리기

		//output(i + 1);//디버깅, board상황 출력

	}

	printf("%d\n", ans);

	return 0;

}