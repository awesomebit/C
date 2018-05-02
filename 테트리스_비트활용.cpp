#include <stdio.h>

int N;//����ũ��

int board[10010 * 3];//������

int block[4];//��

int pos;//block ��ġ

int ans;//���� ����

int mask;

inline void turnArr(int tmp[4][4]){

	int arr[4][4]; register int i, j;

	for (i = 0; i < 3; i++){

		for (j = 0; j < 3; j++){

			arr[j][2 - i] = tmp[i][j];//90�� ȸ��

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

	for (i = 0; i < 3; i++){//1.�������ޱ�

		for (j = 0; j < 3; j++){

			scanf("%d", &tmp[i][j]);

		}

	}

	scanf("%d %d", &turn, &pos);

	turn &= 3;//2.ȸ��, turn %= 4;

	while (turn--) turnArr(tmp);//90���� ȸ��

	int orbits = 0;

	for (i = 0; i < 3; i++){//3.���Ϲ����ؼ�����, �迭�� 0�������̹Ƿ�

		block[2 - i] = 0;

		for (j = 0; j < 3; j++){

			block[2 - i] += (tmp[i][j] << j);

		}

		orbits |= block[2 - i];

	}

	while (!(orbits & 1)){//4.���ʺ��� ���̱�(��ƮƯ���� ��� shift)

		for (i = 0; i < 3; i++) block[i] >>= 1;

		orbits >>= 1;

	}

	while (!block[0]){//5.�Ʒ����� ���̱�

		for (i = 0; i < 3; i++) block[i] = block[i + 1];

	}

	//6.���������� �̵�(������ �̵�, ��ƮƯ���� �·� shift)

	int wall = ~mask;//��

	for (i = 0; i < pos; i++){

		if ((orbits << 1) & wall) break;//0�� �ƴϸ� ���� �Ѿ

		orbits <<= 1;

		for (j = 0; j < 3; j++) block[j] <<= 1;

	}

}

inline int collision(int row){

	register int i;

	for (i = 0; i < 3; i++){

		if (board[row + i] & block[i]) return 1;//collision�߻�

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

		if (board[row] == mask){//���ٿϼ�, row �� ����

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

	mask = (1 << N) - 1;//���ٿϼ� Ȯ�ο�(0����Ʈ���� N����Ʈ�� ��� 1�� �� �����)

	for (i = 0; i < M; i++){

		makeBlock();//�������ޱ�

		dropBlock();//������Ʈ����

		//output(i + 1);//�����, board��Ȳ ���

	}

	printf("%d\n", ans);

	return 0;

}