#include <stdio.h>

int N;
int A[100][5];	//[0]~[2]����, [3]strike, [4]ball

void inputData()
{
	scanf("%d", &N);
	for (register int i = 0; i < N; i++){
		for (register int j = 0; j < 5; j++){
			scanf("%1d", &A[i][j]);	//���� ���ڸ��� �б�
		}
	}
}
inline int check(int* num){	//inline int check(int num[3]), inline int check(int num[])
	int sel[10] = { 0 }; register int i, j;
	for (i = 0; i < 3; i++){
		if ((num[i] == 0) || (sel[num[i]] != 0)) return 0;	//0���Կ���, ���� ���� üũ
		sel[num[i]] = 1;
	}
	for (i = 0; i < N; i++){	//�Է� �����Ϳ� ��
		int strike = 0, ball = 0;
		for (j = 0; j < 3; j++){
			if (num[j] == A[i][j]) strike++;	//���� ���ڿ� ���� �ڸ�
			else if (sel[A[i][j]] == 1) ball++;	//�ڸ��� �ٸ����� ���ڴ� ����
		}
		if ((A[i][3] != strike) || (A[i][4] != ball)) return 0;	//�� �ĺ� �ƴ�
	}
	return 1;	//����(�� �ĺ� ���ɼ� ����)
}
int solve()
{
	register int a, cnt = 0; int num[3];
	for (a = 123; a <= 987; a++){
		num[0] = a / 100;	//100�� �ڸ�
		num[1] = a % 100 / 10;	//10�� �ڸ�
		num[2] = a % 10;	//1�� �ڸ�
		cnt += check(num);	//�����ϸ� 1, �ƴϸ� 0
	}
	return cnt;
}

int main()
{
	inputData();
	int ans = solve();
	printf("%d\n", ans);

	return 0;
}