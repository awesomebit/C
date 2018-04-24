#include <stdio.h>

int N;
int A[100][5];	//[0]~[2]숫자, [3]strike, [4]ball

void inputData()
{
	scanf("%d", &N);
	for (register int i = 0; i < N; i++){
		for (register int j = 0; j < 5; j++){
			scanf("%1d", &A[i][j]);	//숫자 한자리씩 읽기
		}
	}
}
inline int check(int* num){	//inline int check(int num[3]), inline int check(int num[])
	int sel[10] = { 0 }; register int i, j;
	for (i = 0; i < 3; i++){
		if ((num[i] == 0) || (sel[num[i]] != 0)) return 0;	//0포함여부, 같은 숫자 체크
		sel[num[i]] = 1;
	}
	for (i = 0; i < N; i++){	//입력 데이터와 비교
		int strike = 0, ball = 0;
		for (j = 0; j < 3; j++){
			if (num[j] == A[i][j]) strike++;	//같은 숫자에 같은 자리
			else if (sel[A[i][j]] == 1) ball++;	//자리는 다르지만 숫자는 있음
		}
		if ((A[i][3] != strike) || (A[i][4] != ball)) return 0;	//답 후보 아님
	}
	return 1;	//성공(답 후보 가능성 있음)
}
int solve()
{
	register int a, cnt = 0; int num[3];
	for (a = 123; a <= 987; a++){
		num[0] = a / 100;	//100의 자리
		num[1] = a % 100 / 10;	//10의 자리
		num[2] = a % 10;	//1의 자리
		cnt += check(num);	//가능하면 1, 아니면 0
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