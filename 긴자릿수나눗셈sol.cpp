#include <stdio.h>
char N[210];
char M[210];

inline int strlength(char* a){
	register int cnt;
	for (cnt = 0; a[cnt]; cnt++);
	return cnt;
}

inline int strcompare(char* a, char* b){
	register int i;
	for (i = 0; a[i] && b[i]; i++) if (a[i] != b[i]) break;
	return a[i] - b[i];
}

int InputData(){
	scanf("%s", N); scanf("%s", M);
	if ((N[0] == '0') || (M[0] == '0')) return 0;
	return 1;
}

inline int divsub(int* a, int* b, int len){
	register int i;
	for (i = 0; i < len; i++){ //»¬¼À°¡´É¿©ºÎÆÇ´Ü
		if (a[i] > b[i]) break; //»¬¼À °¡´É
		if (a[i] < b[i]) return 0; //»¬¼À ºÒ°¡´É
	}
	//»¬¼À
	for (i = len - 1; i >= 0; i--){ //»¬¼À
		a[i] -= b[i];
		if (a[i] < 0){ //ºô¸²¹ß»ı
			a[i - 1]--; a[i] += 10;
		}
	}
	return 1;
}

void divide(char* a, char* b, int alen, int blen){
	int A[210] = { 0 }; int B[210] = { 0 }; int C[210] = { 0 };
	register int i, j, len = alen - blen + 1;
	for (i = 0; i < alen; i++) A[i] = a[i] - '0';
	for (i = 0; i < blen; i++) B[i] = b[i] - '0';
	for (i = 0; i < len; i++){
		C[i] = 0; //ÃÊ±âÈ­
		while (divsub(&A[i], B, blen)) C[i]++; //»¬ ¼ö ÀÖÀ¸¸é ¸ò Áõ°¡(ÃÖ´ë 9¹ø »¬¼À)
		A[i + 1] += A[i] * 10; A[i] = 0;
	}
	for (i = (C[0] == 0); i < len; i++) printf("%d", C[i]);
	printf("\n");
}

void solve(){
	int nlen = strlength(N), mlen = strlength(M);
	if ((nlen > mlen) || ((nlen == mlen) && strcompare(N, M) > 0)){
		divide(N, M, nlen, mlen);
	}
	else{
		divide(M, N, mlen, nlen);
	}
}

int main(){
	for (;;){
		if (InputData() == 0) break;
		solve();
	}

	return 0;
}