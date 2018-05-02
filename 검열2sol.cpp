#include <stdio.h>
char S[1000000 + 10];
char T[1000000 + 10];
int tfail[1000000 + 10];
int sfail[1000000 + 10];

inline int strlength(char* a){
	register int cnt;
	for (cnt = 0; a[cnt]; cnt++);
	return cnt;
}

void InputData(){
	scanf("%s", &S[1]);
	scanf("%s", &T[1]);
}

void preKMP(int tlen){
	register int i, k;
	for (i = 2, k = 0; i <= tlen; i++){
		while (k && (T[k + 1] != T[i])) k = tfail[k];
		if (T[k + 1] == T[i]) tfail[i] = ++k;
		else tfail[i] = 0; //�ʱ�ȭ ���� �ʾ�����
	}
}

void KMP(int slen, int tlen){
	register int i, j, k;
	for (i = j = 1; j <= slen; i++, j++){
		S[i] = S[j]; //�����ϰ� ���� ��ܿ;� ��
		sfail[i] = 0; //��� �� �ֱ� ������ �ʱ�ȭ �ʿ�
		while (k && (T[k + 1] != S[i])) k = tfail[k];
		if (T[k + 1] == S[i]){
			sfail[i] = ++k;
			if (k == tlen){ //��ġ�ϴ� ���ڿ� ã��
				i -= tlen; //����
				k = sfail[i]; //k ��ܿ���
			}
		}
	}
	S[i] = 0; //i�� �������̹Ƿ� NULL����
}

int main(){
	InputData();
	int tlen = strlength(&T[1]);
	int slen = strlength(&S[1]);
	preKMP(tlen);
	KMP(slen, tlen);
	printf("%s\n", &S[1]);
	return 0;
}