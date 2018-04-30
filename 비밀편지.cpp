#include <stdio.h>
int N; //문자 개수
int in[10];
char dec2char[] = "ABCDEFGH";
int num[8] = { 0x0, 0xF, 0x13, 0x1c, 0x26, 0x29, 0x35, 0x3a };
char sol[11];
void InputData(){
	char str[10 * 6 + 10];
	scanf("%d", &N);
	scanf("%s", str);
	for (register int i = 1; i <= N; i++){
		in[i] = 0;
		for (register int j = 0; j < 6; j++){
			in[i] = in[i] * 2 + str[(i - 1) * 6 + j] - '0';
		}
	}
}
inline int getChar(int code){
	for (register int i = 0; i < 8; i++){
		int bits = num[i] ^ code;
		bits = bits & (bits - 1);
		if (bits == 0) return i;
	}
	return -1;
}
void solve(){
	for (register int i = 1; i <= N; i++){
		int ret = getChar(in[i]);
		if (ret == -1){
			printf("%d\n", i); return;
		}
		sol[i - 1] = dec2char[ret];
	}
	sol[N] = 0;
	printf("%s\n", sol);
}
int main(){
	InputData();
	solve();
	return 0;
}