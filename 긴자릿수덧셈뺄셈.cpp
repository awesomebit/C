#include <stdio.h>

char A[210];

char B[210];

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

	scanf("%s", A); scanf("%s", B);

	if ((A[0] == '0') && (B[0] == '0')) return 0;

	return 1;

}

void OutputData(int *a, int alen){

	register int i;

	for (i = 0; i < alen; i++) if (a[i]) break;

	for (; i <= alen; i++) printf("%d", a[i]);

	printf("\n");

}

void addsub(char *a, char *b, int alen, int blen){

	int A[210] = { 0 }; int B[210] = { 0 };

	int sum[210] = { 0 }; int sub[210] = { 0 };

	register int i, j;

	for (i = alen - 1, j = alen; i >= 0; i--, j--) A[j] = a[i] - '0';

	for (i = blen - 1, j = alen; i >= 0; i--, j--) B[j] = b[i] - '0';

	for (i = alen; i > 0; i--){

		sum[i] += A[i] + B[i];

		if (sum[i] > 9){//올림발생

			sum[i - 1]++; sum[i] -= 10;

		}

	}

	for (i = alen; i > 0; i--){

		sub[i] += A[i] - B[i];

		if (sub[i] < 0){//빌림발생

			sub[i - 1]--; sub[i] += 10;

		}

	}

	OutputData(sum, alen); OutputData(sub, alen);

}

void solve(){

	int alen = strlength(A); int blen = strlength(B);

	if ((alen > blen) ||

		((alen == blen) && (strcompare(A, B) > 0))){

		addsub(A, B, alen, blen);

	}

	else{

		addsub(B, A, blen, alen);

	}

}

int main(){

	for (;;){

		if (InputData() == 0) break;

		solve();

	}

	return 0;
}