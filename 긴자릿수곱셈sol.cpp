#include <stdio.h>

char A[110];

char B[110];

inline int strlength(char *a){

	register int cnt;

	for (cnt = 0; a[cnt]; cnt++);

	return cnt;

}

inline int strcompare(char *a, char *b){

	register int i;

	for (i = 0; a[i] && b[i]; i++) if (a[i] != b[i]) break;

	return a[i] - b[i];

}

int InputData(){

	scanf("%s", A); if (A[0] == '0') return 0;

	scanf("%s", B);

	return 1;

}

void mul(char *a, char *b, int alen, int blen){

	int C[210] = { 0 };

	register int i, j, len = alen + blen - 1;

	for (i = 0; i < alen; i++){

		for (j = 0; j < blen; j++){

			C[i + j] += (a[i] - '0') * (b[j] - '0');

		}

	}

	for (i = len - 1; i > 0; i--){

		if (C[i] > 9){//올림발생

			C[i - 1] += C[i] / 10; C[i] %= 10;

		}

	}

	for (i = 0; i < len; i++) printf("%d", C[i]);

	printf("\n");

}

void solve(){

	if (B[0] == '0'){//곱하면 0이므로

		printf("0\n"); return;

	}

	char *a = A, *b = B, alen, blen; int sign = 1;

	if (A[0] == '-'){//부호 제외

		a++; sign *= -1;

	}

	if (B[0] == '-'){//부호 제외

		b++; sign *= -1;

	}

	alen = strlength(a); blen = strlength(b);

	if (sign == -1) printf("-");

	mul(a, b, alen, blen);

}

int main(){

	for (;;){

		if (InputData() == 0) break;

		solve();

	}

	return 0;

}